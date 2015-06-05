ifeq ($(CONFIG_SUPPORT_OPENWRT),y)
EXTRA_CFLAGS = -I$(src)/../src/include -I$(src)/../src/ate/include
DRV_NAME = mt7620
SRC_DIR = ../src
obj-m += $(DRV_NAME).o
else
EXTRA_CFLAGS = -Idrivers/net/wireless/rt2860v2/include -Idrivers/net/wireless/rt2860v2/ate/include
DRV_NAME = rt2860v2_ap
SRC_DIR = ../rt2860v2
obj-$(CONFIG_RT2860V2_AP) += $(DRV_NAME).o
endif


$(DRV_NAME)-objs += $(SRC_DIR)/common/crypt_md5.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/crypt_sha2.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/crypt_hmac.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/crypt_aes.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/crypt_arc4.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/mlme.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/cmm_wep.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/action.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/ba_action.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/cmm_data.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/rtmp_init.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/rtmp_init_inf.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/cmm_tkip.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/cmm_aes.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/cmm_sync.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/cmm_sanity.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/cmm_info.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/cmm_cfg.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/cmm_radar.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/cmm_wpa.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/spectrum.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/ps.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/uapsd.o

$(DRV_NAME)-objs += $(SRC_DIR)/common/rtmp_timer.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/rt_channel.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/cmm_profile.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/cmm_asic.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/cmm_cmd.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/rtmp_swmcu.o

$(DRV_NAME)-objs += $(SRC_DIR)/common/eeprom.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/ee_flash.o

$(DRV_NAME)-objs += $(SRC_DIR)/common/cmm_mac_pci.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/cmm_data_pci.o

$(DRV_NAME)-objs += $(SRC_DIR)/common/cmm_rf_cal.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/cmm_loft_cal.o

$(DRV_NAME)-objs += $(SRC_DIR)/ap/ap.o
$(DRV_NAME)-objs += $(SRC_DIR)/ap/ap_assoc.o
$(DRV_NAME)-objs += $(SRC_DIR)/ap/ap_auth.o
$(DRV_NAME)-objs += $(SRC_DIR)/ap/ap_connect.o
$(DRV_NAME)-objs += $(SRC_DIR)/ap/ap_mlme.o
$(DRV_NAME)-objs += $(SRC_DIR)/ap/ap_sanity.o
$(DRV_NAME)-objs += $(SRC_DIR)/ap/ap_sync.o
$(DRV_NAME)-objs += $(SRC_DIR)/ap/ap_wpa.o
$(DRV_NAME)-objs += $(SRC_DIR)/ap/ap_data.o
$(DRV_NAME)-objs += $(SRC_DIR)/ap/ap_autoChSel.o
$(DRV_NAME)-objs += $(SRC_DIR)/ap/ap_qload.o
$(DRV_NAME)-objs += $(SRC_DIR)/ap/ap_cfg.o

$(DRV_NAME)-objs += $(SRC_DIR)/rate_ctrl/ra_ctrl.o
$(DRV_NAME)-objs += $(SRC_DIR)/rate_ctrl/alg_legacy.o
$(DRV_NAME)-objs += $(SRC_DIR)/rate_ctrl/alg_ags.o

$(DRV_NAME)-objs += $(SRC_DIR)/os/linux/rt_proc.o
$(DRV_NAME)-objs += $(SRC_DIR)/os/linux/rt_linux.o
$(DRV_NAME)-objs += $(SRC_DIR)/os/linux/rt_profile.o
$(DRV_NAME)-objs += $(SRC_DIR)/os/linux/rt_main_dev.o
$(DRV_NAME)-objs += $(SRC_DIR)/os/linux/ap_ioctl.o
$(DRV_NAME)-objs += $(SRC_DIR)/os/linux/rt_pci_rbus.o
$(DRV_NAME)-objs += $(SRC_DIR)/os/linux/rt_rbus_pci_drv.o
$(DRV_NAME)-objs += $(SRC_DIR)/os/linux/rt_rbus_pci_util.o
$(DRV_NAME)-objs += $(SRC_DIR)/os/linux/rbus_main_dev.o

$(DRV_NAME)-objs += $(SRC_DIR)/ate/common/rt_ate.o
$(DRV_NAME)-objs += $(SRC_DIR)/ate/common/rt_qa.o
$(DRV_NAME)-objs += $(SRC_DIR)/ate/common/ate_pci.o

$(DRV_NAME)-objs +=  $(SRC_DIR)/common/rt_os_util.o
$(DRV_NAME)-objs +=  $(SRC_DIR)/common/rtmp_swmcu.o
$(DRV_NAME)-objs +=  $(SRC_DIR)/chips/rtmp_chip.o
$(DRV_NAME)-objs +=  $(SRC_DIR)/common/rt_rf.o

ifeq ($(CONFIG_RT2860V2_AP_WMM_ACM),y)
$(DRV_NAME)-objs += $(SRC_DIR)/common/acm_edca.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/acm_comm.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/acm_iocl.o
endif

ifeq ($(CONFIG_RT2860V2_AP_LED),y)
$(DRV_NAME)-objs += $(SRC_DIR)/common/rt_led.o
endif

ifeq ($(CONFIG_RT2860V2_AP_WSC),y)
$(DRV_NAME)-objs += $(SRC_DIR)/common/wsc.o 
$(DRV_NAME)-objs += $(SRC_DIR)/common/wsc_tlv.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/crypt_dh.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/crypt_biginteger.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/wsc_ufd.o
ifeq ($(CONFIG_RT2860V2_AP_WSC_V2),y)
$(DRV_NAME)-objs += $(SRC_DIR)/common/wsc_v2.o
endif
endif

ifeq ($(CONFIG_RT2860V2_AP_WDS),y)
$(DRV_NAME)-objs += $(SRC_DIR)/ap/ap_wds.o
$(DRV_NAME)-objs += $(SRC_DIR)/ap/ap_wds_inf.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/client_wds.o
endif

ifeq ($(CONFIG_RT2860V2_AP_MBSS),y)
$(DRV_NAME)-objs += $(SRC_DIR)/ap/ap_mbss.o
$(DRV_NAME)-objs += $(SRC_DIR)/ap/ap_mbss_inf.o
endif

ifeq ($(CONFIG_RT2860V2_AP_APCLI),y)
$(DRV_NAME)-objs += $(SRC_DIR)/ap/ap_apcli.o
$(DRV_NAME)-objs += $(SRC_DIR)/ap/ap_apcli_inf.o
$(DRV_NAME)-objs += $(SRC_DIR)/ap/apcli_assoc.o
$(DRV_NAME)-objs += $(SRC_DIR)/ap/apcli_auth.o
$(DRV_NAME)-objs += $(SRC_DIR)/ap/apcli_ctrl.o
$(DRV_NAME)-objs += $(SRC_DIR)/ap/apcli_sync.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/cmm_mat.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/cmm_mat_iparp.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/cmm_mat_pppoe.o
$(DRV_NAME)-objs += $(SRC_DIR)/common/cmm_mat_ipv6.o
endif

ifeq ($(CONFIG_RT2860V2_AP_MAC_REPEATER),y)
$(DRV_NAME)-objs += $(SRC_DIR)/ap/ap_repeater.o
endif

#ifeq ($(CONFIG_RT2860V2_AP_WAPI),y)
#$(DRV_NAME)-objs += $(SRC_DIR)/common/wapi.o
#$(DRV_NAME)-objs += wapi_crypt.obj
#$(DRV_NAME)-objs += wapi_sms4.obj
#endif

ifeq ($(CONFIG_RT2860V2_AP_IGMP_SNOOP),y)
$(DRV_NAME)-objs += $(SRC_DIR)/common/igmp_snoop.o
endif

ifeq ($(CONFIG_RT2860V2_AP_NETIF_BLOCK),y)
$(DRV_NAME)-objs += $(SRC_DIR)/common/netif_block.o
endif

ifeq ($(CONFIG_RT2860V2_AP_DFS),y)
$(DRV_NAME)-objs += $(SRC_DIR)/common/cmm_dfs.o
endif

ifeq ($(CONFIG_RT2860V2_AP_CARRIER),y)
$(DRV_NAME)-objs += $(SRC_DIR)/common/cmm_cs.o
endif

ifeq ($(CONFIG_RT2860V2_AP_DLS),y)
$(DRV_NAME)-objs += $(SRC_DIR)/ap/ap_dls.o
endif

ifeq ($(CONFIG_RT2860V2_AP_IDS),y)
$(DRV_NAME)-objs += $(SRC_DIR)/ap/ap_ids.o
endif

#ifeq ($(CONFIG_RT2860V2_80211R_FT),y)
#$(DRV_NAME)-objs += $(SRC_DIR)/common/ft.o
#$(DRV_NAME)-objs += $(SRC_DIR)/common/ft_tlv.o
#$(DRV_NAME)-objs += $(SRC_DIR)/common/ft_ioctl.o
#$(DRV_NAME)-objs += $(SRC_DIR)/common/ft_rc.o
#$(DRV_NAME)-objs += $(SRC_DIR)/ap/ap_ftkd.o
#endif

#ifeq ($(CONFIG_RT2860V2_80211K_RR),y)
#$(DRV_NAME)-objs += $(SRC_DIR)/common/rrm_tlv.o
#$(DRV_NAME)-objs += $(SRC_DIR)/common/rrm_sanity.o
#$(DRV_NAME)-objs += $(SRC_DIR)/common/rrm.o
#endif

ifeq ($(CONFIG_RT2860V2_AP_VIDEO_TURBINE),y)
$(DRV_NAME)-objs += $(SRC_DIR)/common/cmm_video.o
endif

ifeq ($(CONFIG_RALINK_RT2880),y)
$(DRV_NAME)-objs +=  $(SRC_DIR)/chips/rt2880.o
endif

ifeq ($(CONFIG_RALINK_RT2883),y)
$(DRV_NAME)-objs += $(SRC_DIR)/common/rt_rf.o
$(DRV_NAME)-objs += $(SRC_DIR)/chips/rt2883.o
ifeq ($(CONFIG_RT2860V2_AP_TXBF),y)
$(DRV_NAME)-objs +=  $(SRC_DIR)/common/cmm_txbf.o
endif
endif

ifeq ($(CONFIG_RALINK_RT3883),y)
$(DRV_NAME)-objs += $(SRC_DIR)/common/rt_rf.o
$(DRV_NAME)-objs += $(SRC_DIR)/chips/rt3883.o
ifeq ($(CONFIG_RT2860V2_AP_TXBF),y)
$(DRV_NAME)-objs +=  $(SRC_DIR)/common/cmm_txbf.o
$(DRV_NAME)-objs +=  $(SRC_DIR)/common/cmm_txbf_cal.o
endif
$(DRV_NAME)-objs +=  $(SRC_DIR)/rate_ctrl/alg_grp.o
$(DRV_NAME)-objs +=  $(SRC_DIR)/ate/chips/rt3883_ate.o
endif

ifeq ($(CONFIG_RALINK_RT3052),y)
$(DRV_NAME)-objs +=  $(SRC_DIR)/common/rt_rf.o
$(DRV_NAME)-objs +=  $(SRC_DIR)/chips/rt305x.o
endif

ifeq ($(CONFIG_RALINK_RT3352),y)
$(DRV_NAME)-objs +=  $(SRC_DIR)/common/rt_rf.o
$(DRV_NAME)-objs +=  $(SRC_DIR)/chips/rt305x.o
$(DRV_NAME)-objs +=  $(SRC_DIR)/chips/rt3352.o
endif

ifeq ($(CONFIG_RT3x52),y)
$(DRV_NAME)-objs +=  $(SRC_DIR)/common/rt_rf.o
$(DRV_NAME)-objs +=  $(SRC_DIR)/chips/rt305x.o
$(DRV_NAME)-objs +=  $(SRC_DIR)/chips/rt3352.o
endif

ifeq ($(CONFIG_RALINK_RT5350),y)
$(DRV_NAME)-objs +=  $(SRC_DIR)/common/rt_rf.o
$(DRV_NAME)-objs +=  $(SRC_DIR)/chips/rt305x.o
$(DRV_NAME)-objs +=  $(SRC_DIR)/chips/rt5350.o
endif

ifeq ($(CONFIG_RALINK_RT6352),y)
$(DRV_NAME)-objs +=  $(SRC_DIR)/common/rt_rf.o
$(DRV_NAME)-objs +=  $(SRC_DIR)/chips/rt6352.o
$(DRV_NAME)-objs +=  $(SRC_DIR)/ate/chips/rt6352_ate.o
endif

ifeq ($(CONFIG_RALINK_MT7620),y)
$(DRV_NAME)-objs +=  $(SRC_DIR)/common/rt_rf.o
$(DRV_NAME)-objs +=  $(SRC_DIR)/chips/rt6352.o
$(DRV_NAME)-objs +=  $(SRC_DIR)/ate/chips/rt6352_ate.o
endif

###################
#  CFLAGS
##################
EXTRA_CFLAGS += -DAGGREGATION_SUPPORT -DPIGGYBACK_SUPPORT -DWMM_SUPPORT  -DLINUX \
               -Wall -Wstrict-prototypes -Wno-trigraphs

EXTRA_CFLAGS += -DCONFIG_AP_SUPPORT -DAP_SCAN_SUPPORT -DUAPSD_AP_SUPPORT -DUAPSD_SUPPORT -DRTMP_RBUS_SUPPORT -DRTMP_MAC_PCI
EXTRA_CFLAGS += -DDOT11_N_SUPPORT -DSTATS_COUNT_SUPPORT -DIAPP_SUPPORT -DDOT1X_SUPPORT
EXTRA_CFLAGS += -DRALINK_ATE -DRALINK_QA -DCONFIG_RT2880_ATE_CMD_NEW
EXTRA_CFLAGS += -DCONFIG_RA_NAT_NONE

#provide busy time statistics for every TBTT */
#EXTRA_CFLAGS += -DQLOAD_FUNC_BUSY_TIME_STATS 

# provide busy time alarm mechanism 
# use the function to avoid to locate in some noise environments 
#EXTRA_CFLAGS += -DQLOAD_FUNC_BUSY_TIME_ALARM

ifeq ($(CONFIG_RALINK_RT2880),y)
EXTRA_CFLAGS += -DRT2880
endif

ifeq ($(CONFIG_RALINK_RT2883),y)
EXTRA_CFLAGS += -DRT2883 -DDOT11N_SS3_SUPPORT -DA_BAND_SUPPORT -DRTMP_RF_RW_SUPPORT
ifeq ($(CONFIG_RT2860V2_AP_TXBF),y)
EXTRA_CFLAGS += -DTXBF_SUPPORT
endif
endif

ifeq ($(CONFIG_RALINK_RT3883),y)
EXTRA_CFLAGS += -DRT3883 -DDOT11N_SS3_SUPPORT -DA_BAND_SUPPORT -DRTMP_RF_RW_SUPPORT
EXTRA_CFLAGS += -DRTMP_FLASH_SUPPORT -DCONFIG_SWMCU_SUPPORT
EXTRA_CFLAGS += -DSPECIFIC_BCN_BUF_SUPPORT -DVCORECAL_SUPPORT
EXTRA_CFLAGS += -DRANGE_EXT_SUPPORT
ifeq ($(CONFIG_RT2860V2_AP_TXBF),y)
EXTRA_CFLAGS += -DTXBF_SUPPORT
endif
EXTRA_CFLAGS += -DSTREAM_MODE_SUPPORT -DFIFO_EXT_SUPPORT
endif

ifeq ($(CONFIG_RALINK_RT3052),y)
EXTRA_CFLAGS += -DSPECIFIC_VCORECAL_SUPPORT
ifeq ($(CONFIG_RALINK_RT3350),y)
EXTRA_CFLAGS += -DRT3350 -DRT305x -DRTMP_RF_RW_SUPPORT
else
EXTRA_CFLAGS += -DRT3052 -DRT305x -DRTMP_RF_RW_SUPPORT
endif
endif

ifeq ($(CONFIG_RALINK_RT3352),y)
EXTRA_CFLAGS += -DRT3352 -DRT305x -DRTMP_RF_RW_SUPPORT
EXTRA_CFLAGS += -DSPECIFIC_BCN_BUF_SUPPORT -DVCORECAL_SUPPORT
endif

ifeq ($(CONFIG_RT3x52),y)
EXTRA_CFLAGS += -DRT3052 -DRT3352 -DRT305x -DRTMP_RF_RW_SUPPORT -DSPECIFIC_BCN_BUF_SUPPORT -DVCORECAL_SUPPORT
endif

ifeq ($(CONFIG_RALINK_RT5350),y)
EXTRA_CFLAGS += -DRT5350 -DRT305x -DRTMP_RF_RW_SUPPORT
EXTRA_CFLAGS += -DSPECIFIC_BCN_BUF_SUPPORT -DVCORECAL_SUPPORT
endif

ifeq ($(CONFIG_RALINK_RT6352),y)
EXTRA_CFLAGS += -DRT6352 -DRTMP_RF_RW_SUPPORT -DRF_BANK -DRTMP_FLASH_SUPPORT -DCONFIG_SWMCU_SUPPORT
EXTRA_CFLAGS += -DSPECIFIC_BCN_BUF_SUPPORT -DVCORECAL_SUPPORT
EXTRA_CFLAGS += -DRESOURCE_PRE_ALLOC
EXTRA_CFLAGS += -DENHANCED_STAT_DISPLAY
EXTRA_CFLAGS += -DLOFT_IQ_CAL_SUPPORT
EXTRA_CFLAGS += -DRTMP_TEMPERATURE_CALIBRATION
EXTRA_CFLAGS += -DDYNAMIC_VGA_SUPPORT
EXTRA_CFLAGS += -DMCS_LUT_SUPPORT -DPEER_DELBA_TX_ADAPT
ifeq ($(CONFIG_INTERNAL_PA_EXTERNAL_LNA),y)
EXTRA_CFLAGS += -DRT6352_EL_SUPPORT
endif
ifeq ($(CONFIG_EXTERNAL_PA_EXTERNAL_LNA),y)
EXTRA_CFLAGS += -DRT6352_EP_SUPPORT -DRT6352_EL_SUPPORT
endif
endif

ifeq ($(CONFIG_RALINK_MT7620),y)
EXTRA_CFLAGS += -DRT6352 -DRTMP_RF_RW_SUPPORT -DRF_BANK -DRTMP_FLASH_SUPPORT -DCONFIG_SWMCU_SUPPORT
EXTRA_CFLAGS += -DSPECIFIC_BCN_BUF_SUPPORT -DVCORECAL_SUPPORT
EXTRA_CFLAGS += -DRESOURCE_PRE_ALLOC
EXTRA_CFLAGS += -DENHANCED_STAT_DISPLAY
EXTRA_CFLAGS += -DLOFT_IQ_CAL_SUPPORT
EXTRA_CFLAGS += -DRTMP_TEMPERATURE_CALIBRATION
EXTRA_CFLAGS += -DDYNAMIC_VGA_SUPPORT
EXTRA_CFLAGS += -DMCS_LUT_SUPPORT -DPEER_DELBA_TX_ADAPT
ifeq ($(CONFIG_INTERNAL_PA_EXTERNAL_LNA),y)
EXTRA_CFLAGS += -DRT6352_EL_SUPPORT
endif
ifeq ($(CONFIG_EXTERNAL_PA_EXTERNAL_LNA),y)
EXTRA_CFLAGS += -DRT6352_EP_SUPPORT -DRT6352_EL_SUPPORT
endif
endif

ifeq ($(CONFIG_RT2860V2_AP_DLS),y)
EXTRA_CFLAGS += -DQOS_DLS_SUPPORT
EXTRA_CFLAGS += -DAP_DLS_SUPPORT
endif

ifeq ($(CONFIG_RT2860V2_AP_IDS),y)
EXTRA_CFLAGS += -DIDS_SUPPORT
endif

ifeq ($(CONFIG_RT2860V2_AP_DFS),y)
EXTRA_CFLAGS += -DDFS_SUPPORT
endif

ifeq ($(CONFIG_RT2860V2_AP_CARRIER),y)
EXTRA_CFLAGS += -DCARRIER_DETECTION_SUPPORT
endif

ifeq ($(CONFIG_RT2860V2_AUTO_CH_SELECT_ENCANCE),y)
EXTRA_CFLAGS += -DAUTO_CH_SELECT_ENHANCE
endif

ifeq ($(CONFIG_RT2860V2_AP_80211N_DRAFT3),y)
EXTRA_CFLAGS += -DDOT11N_DRAFT3
endif

ifeq ($(CONFIG_RT2860V2_SNMP),y)
EXTRA_CFLAGS += -DSNMP_SUPPORT
endif

ifeq ($(CONFIG_RT2860V2_MCAST_RATE_SPECIFIC),y)
EXTRA_CFLAGS += -DMCAST_RATE_SPECIFIC
endif

#ifeq ($(CONFIG_RT2860V2_AP_WMM_ACM),y)
#EXTRA_CFLAGS += -DWMM_ACM_SUPPORT
#endif

ifeq ($(CONFIG_RT2860V2_AP_LED),y)
EXTRA_CFLAGS += -DLED_CONTROL_SUPPORT -DCONFIG_SWMCU_SUPPORT
ifeq ($(CONFIG_RT2860V2_AP_WSC),y)
EXTRA_CFLAGS += -DWSC_LED_SUPPORT
endif
endif

ifeq ($(CONFIG_RT2860V2_AP_WSC),y)
EXTRA_CFLAGS += -DWSC_AP_SUPPORT
ifeq ($(CONFIG_RT2860V2_AP_WSC_V2),y)
EXTRA_CFLAGS += -DWSC_V2_SUPPORT
endif
endif

ifeq ($(CONFIG_RT2860V2_AP_LLTD),y)
EXTRA_CFLAGS += -DLLTD_SUPPORT
endif

ifeq ($(CONFIG_RT2860V2_AP_WDS),y)
EXTRA_CFLAGS += -DWDS_SUPPORT
endif

ifeq ($(CONFIG_RT2860V2_AP_MBSS),y)
EXTRA_CFLAGS += -DMBSS_SUPPORT
endif

ifeq ($(CONFIG_NEW_MBSSID_MODE),y)
EXTRA_CFLAGS += -DNEW_MBSSID_MODE
ifeq ($(CONFIG_RALINK_RT6352),y)
EXTRA_CFLAGS += -DENHANCE_NEW_MBSSID_MODE
endif
ifeq ($(CONFIG_RALINK_MT7620),y)
EXTRA_CFLAGS += -DENHANCE_NEW_MBSSID_MODE
endif
endif

ifeq ($(CONFIG_RT2860V2_AP_APCLI),y)
EXTRA_CFLAGS += -DAPCLI_SUPPORT
EXTRA_CFLAGS += -DMAT_SUPPORT
EXTRA_CFLAGS += -DAPCLI_CONNECTION_TRIAL
endif

ifeq ($(CONFIG_RT2860V2_AP_MAC_REPEATER),y)
ifeq ($(CONFIG_RALINK_MT7620),y)
EXTRA_CFLAGS += -DMAC_APCLI_SUPPORT
endif
EXTRA_CFLAGS += -DMAC_REPEATER_SUPPORT
endif

ifeq ($(CONFIG_RT2860V2_AP_32B_DESC),y)
EXTRA_CFLAGS += -DDESC_32B_SUPPORT
endif

ifeq ($(CONFIG_RT2860V2_AP_IGMP_SNOOP),y)
EXTRA_CFLAGS += -DIGMP_SNOOP_SUPPORT
endif

ifeq ($(CONFIG_RT2860V2_AP_NETIF_BLOCK),y)
EXTRA_CFLAGS += -DBLOCK_NET_IF
endif

ifeq ($(CONFIG_RT2860V2_HW_ANTENNA_DIVERSITY),y)
EXTRA_CFLAGS   += -DHW_ANTENNA_DIVERSITY_SUPPORT
endif

ifeq ($(CONFIG_RT2860V2_AP_WAPI),y)
EXTRA_CFLAGS   += -DWAPI_SUPPORT
ifeq ($(CONFIG_RALINK_RT3052),y)
EXTRA_CFLAGS   += -DSOFT_ENCRYPT
endif
endif

ifeq ($(CONFIG_RT2860V2_AP_COC),y)
EXTRA_CFLAGS   += -DGREENAP_SUPPORT -DCOC_SUPPORT
endif

ifeq ($(CONFIG_BAND_STEERING),y)
EXTRA_CFLAGS += -DBAND_STEERING
$(DRV_NAME)-objs +=  $(SRC_DIR)/ap/ap_band_steering.o
endif

ifeq ($(CONFIG_RT2860V2_EXT_CHANNEL_LIST),y)
EXTRA_CFLAGS   += -DEXT_BUILD_CHANNEL_LIST
endif

ifeq ($(CONFIG_KTHREAD),y)
EXTRA_CFLAGS   += -DKTHREAD_SUPPORT
endif

ifeq ($(CONFIG_RT2860V2_AP_MEMORY_OPTIMIZATION),y)
EXTRA_CFLAGS   += -DMEMORY_OPTIMIZATION
else
EXTRA_CFLAGS   += -DDBG
endif

ifeq ($(CONFIG_RT2860V2_AP_VIDEO_TURBINE),y)
EXTRA_CFLAGS   += -DVIDEO_TURBINE_SUPPORT
endif

ifeq ($(CONFIG_RA_NETWORK_WORKQUEUE_BH),y)
EXTRA_CFLAGS   += -DWORKQUEUE_BH
endif

ifeq ($(CONFIG_RT2860V2_AP_INTELLIGENT_RATE_ADAPTION),y)
EXTRA_CFLAGS   += -DNEW_RATE_ADAPT_SUPPORT
endif

ifeq ($(CONFIG_RT2860V2_AP_RTMP_INTERNAL_TX_ALC),y)
EXTRA_CFLAGS   += -DRTMP_INTERNAL_TX_ALC
endif

ifeq ($(CONFIG_RT2860V2_AP_RTMP_TEMPERATURE_COMPENSATION),y)
EXTRA_CFLAGS   += -DRTMP_TEMPERATURE_COMPENSATION
endif

ifeq ($(CONFIG_RT2860V2_ADJ_PWR_CONSUMPTION_SUPPORT),y)
EXTRA_CFLAGS   += -DADJUST_POWER_CONSUMPTION_SUPPORT
endif

ifeq ($(CONFIG_RT2860V2_SINGLE_SKU),y)
ifeq ($(CONFIG_RALINK_MT7620),y)
EXTRA_CFLAGS   += -DSINGLE_SKU_V2
else
EXTRA_CFLAGS   += -DSINGLE_SKU
endif
endif

