/*
 ***************************************************************************
 * Ralink Tech Inc.
 * 4F, No. 2 Technology 5th Rd.
 * Science-based Industrial Park
 * Hsin-chu, Taiwan, R.O.C.
 *
 * (c) Copyright 2002-2006, Ralink Technology, Inc.
 *
 * All rights reserved.	Ralink's source	code is	an unpublished work	and	the
 * use of a	copyright notice does not imply	otherwise. This	source code
 * contains	confidential trade secret material of Ralink Tech. Any attemp
 * or participation	in deciphering,	decoding, reverse engineering or in	any
 * way altering	the	source code	is stricitly prohibited, unless	the	prior
 * written consent of Ralink Technology, Inc. is obtained.
 ***************************************************************************

	Module Name:
	mesh.c

	Abstract:

	Revision History:
	Who			When			What
	--------	----------		----------------------------------------------
	Fonchi		2007-06-25      For mesh (802.11s) support.
*/
#define RTMP_MODULE_OS

#ifdef MESH_SUPPORT


/*#include "rt_config.h" */
/*#include "mesh_sanity.h" */
#include "rtmp_comm.h"
#include "rt_os_util.h"
#include "rt_os_net.h"

/*static VOID MeshCfgInit( */
/*	IN PRTMP_ADAPTER pAd, */
/*	IN PSTRING		 pHostName); */


/*
========================================================================
Routine Description:
    Init Mesh function.

Arguments:
    ad_p            points to our adapter
    main_dev_p      points to the main BSS network interface

Return Value:
    None

Note:
	1. Only create and initialize virtual network interfaces.
	2. No main network interface here.
========================================================================
*/
VOID RTMP_Mesh_Init(
	IN VOID 				*pAd,
	IN PNET_DEV				main_dev_p,
	IN PSTRING				pHostName)
{
	RTMP_OS_NETDEV_OP_HOOK	netDevOpHook;
	ULONG OpMode;


	/* init operation functions */
	NdisZeroMemory((PUCHAR)&netDevOpHook, sizeof(RTMP_OS_NETDEV_OP_HOOK));
	netDevOpHook.open = Mesh_VirtualIF_Open;
	netDevOpHook.stop = Mesh_VirtualIF_Close;
	netDevOpHook.xmit = Mesh_VirtualIF_PacketSend;
	netDevOpHook.ioctl = Mesh_VirtualIF_Ioctl;	

	/* init operation functions */
	RTMP_DRIVER_OP_MODE_GET(pAd, &OpMode);

#ifdef CONFIG_STA_SUPPORT
#if WIRELESS_EXT >= 12
	if (OpMode == OPMODE_STA)
	{
		netDevOpHook.iw_handler = (void *)&rt28xx_iw_handler_def;
	}
#endif /*WIRELESS_EXT >= 12 */
#endif /* CONFIG_STA_SUPPORT */

#ifdef CONFIG_APSTA_MIXED_SUPPORT
#if WIRELESS_EXT >= 12
	if (OpMode == OPMODE_AP)
	{
		netDevOpHook.iw_handler = &rt28xx_ap_iw_handler_def;
	}
#endif /*WIRELESS_EXT >= 12 */
#endif /* CONFIG_APSTA_MIXED_SUPPORT */

	RTMP_COM_IoctlHandle(pAd, NULL, CMD_RTPRIV_IOCTL_MESH_INIT,
						0, &netDevOpHook, 0);


	
} /* End of RTMP_Mesh_Init */


/*
========================================================================
Routine Description:
    Open a virtual network interface.

Arguments:
    pDev           which WLAN network interface

Return Value:
    0: open successfully
    otherwise: open fail

Note:
========================================================================
*/
INT Mesh_VirtualIF_Open(
	IN PNET_DEV		pDev)
{
	VOID *pAd;

	pAd = RTMP_OS_NETDEV_GET_PRIV(pDev);
	ASSERT(pAd);

	DBGPRINT(RT_DEBUG_TRACE, ("%s: ===> %s\n", __FUNCTION__, RTMP_OS_NETDEV_GET_DEVNAME(pDev)));
	

	if (RTMP_COM_IoctlHandle(pAd, NULL, CMD_RTPRIV_IOCTL_MESH_OPEN_PRE, 0,
							pDev, 0) != NDIS_STATUS_SUCCESS)
		return -1;

	if (VIRTUAL_IF_UP(pAd) != 0)
		return -1;

	/* increase MODULE use count */
	RT_MOD_INC_USE_COUNT();

	RTMP_OS_NETDEV_START_QUEUE(pDev);

	if (RTMP_COM_IoctlHandle(pAd, NULL, CMD_RTPRIV_IOCTL_MESH_OPEN_POST, 0,
							pDev, 0) != NDIS_STATUS_SUCCESS)
		return -1;


	DBGPRINT(RT_DEBUG_TRACE, ("%s: <=== %s\n", __FUNCTION__, RTMP_OS_NETDEV_GET_DEVNAME(pDev)));

	return 0;
}


/*
========================================================================
Routine Description:
    Close a virtual network interface.

Arguments:
    dev_p           which WLAN network interface

Return Value:
    0: close successfully
    otherwise: close fail

Note:
========================================================================
*/
INT Mesh_VirtualIF_Close(
	IN	PNET_DEV	pDev)
{
	VOID *pAd;

	pAd = RTMP_OS_NETDEV_GET_PRIV(pDev);
	ASSERT(pAd);

	DBGPRINT(RT_DEBUG_TRACE, ("%s: ===> %s\n", __FUNCTION__, RTMP_OS_NETDEV_GET_DEVNAME(pDev)));
	

	/* stop mesh. */
	RTMP_OS_NETDEV_STOP_QUEUE(pDev);

	RTMP_COM_IoctlHandle(pAd, NULL, CMD_RTPRIV_IOCTL_MESH_CLOSE, 0, pDev, 0);


	VIRTUAL_IF_DOWN(pAd);

	RT_MOD_DEC_USE_COUNT();

	return 0;
} 


/*
========================================================================
Routine Description:
    Send a packet to WLAN.

Arguments:
    skb_p           points to our adapter
    dev_p           which WLAN network interface

Return Value:
    0: transmit successfully
    otherwise: transmit fail

Note:
========================================================================
*/
INT Mesh_VirtualIF_PacketSend(
	IN PNDIS_PACKET 	pPktSrc, 
	IN PNET_DEV			pDev)
{

	MEM_DBG_PKT_ALLOC_INC(pPktSrc);

	if(!(RTMP_OS_NETDEV_STATE_RUNNING(pDev)))
	{
		/* the interface is down */
		RELEASE_NDIS_PACKET(NULL, pPktSrc, NDIS_STATUS_FAILURE);
		return 0;
	}

	return MESH_PacketSend(pPktSrc, pDev, rt28xx_packet_xmit);


} /* End of Mesh_VirtualIF_PacketSend */


/*
========================================================================
Routine Description:
    IOCTL to WLAN.

Arguments:
    dev_p           which WLAN network interface
    rq_p            command information
    cmd             command ID

Return Value:
    0: IOCTL successfully
    otherwise: IOCTL fail

Note:
    SIOCETHTOOL     8946    New drivers use this ETHTOOL interface to
                            report link failure activity.
========================================================================
*/
INT Mesh_VirtualIF_Ioctl(
	IN PNET_DEV				dev_p, 
	IN OUT VOID 			*rq_p, 
	IN INT 					cmd)
{
/*	if (dev_p->priv_flags == INT_MESH) */
		return rt28xx_ioctl(dev_p, rq_p, cmd);
/*	else */
/*		return -1; */
} /* End of Mesh_VirtualIF_Ioctl */



#ifdef LINUX
#if (WIRELESS_EXT >= 12)
struct iw_statistics *Mesh_VirtualIF_get_wireless_stats(
	IN  struct net_device *net_dev);
#endif
#endif /* LINUX */


VOID RTMP_Mesh_Remove(
	IN VOID 			*pAd)
{

	RTMP_COM_IoctlHandle(pAd, NULL, CMD_RTPRIV_IOCTL_MESH_REMOVE, 0, NULL, 0);

} /* End of RTMP_Mesh_Remove */


#endif /* MESH_SUPPORT */
