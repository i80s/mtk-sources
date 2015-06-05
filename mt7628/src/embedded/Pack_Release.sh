EmbeddedDir=`pwd`
BaseCodeDir=`dirname $EmbeddedDir`
HomeDir=`dirname $BaseCodeDir`
dir_main=mt_wifi
dir_ap=mt_wifi_ap
dir_sta=mt_wifi_sta
release_profile=$BaseCodeDir/Release.log
#module_name=`basename $BaseCodeDir`
module_name=`cat $release_profile | line`
release_version=`sed -e '1d' $release_profile | line`
release_date=`sed -e '1,2d' $release_profile | line`
package_name=$module_name\_$release_version\_$release_date
############################

	cd $HomeDir

	### Creat dir_main ###
	if [ -d $dir_main ]; then
		rm -rf $dir_main
	fi

	if [ -d $dir_ap ]; then
		rm -rf $dir_ap
	fi
	
	if [ -d $dir_sta ]; then
		rm -rf $dir_sta
	fi
	
	cp -a $BaseCodeDir $dir_main
	#cp Kconfig $dir_main/
	rm $dir_main/embedded/Pack_Release.sh $dir_main/Release.log

	#cp -a $BaseCodeDir/$dir_ap ./
	mv $dir_main/embedded/$dir_ap ./
	#mv $dir_main/embedded/$dir_sta ./

	### Creat dir_ap ###
	#if [ -d $dir_ap ]; then
	#	rm -rf $dir_ap
	#fi
	#mkdir $dir_ap
	#if [ ! -d $dir_ap ]; then
    #    echo "Error! Cannot creat folder [$dir_ap]"
	#	exit 1
    #fi
	#
	#
	#cp $BaseCodeDir/os/linux/Makefile.rlt_wifi_ap $dir_ap/Makefile
	#cp $BaseCodeDir/os/linux/Kconfig.rlt_wifi_ap $dir_ap/Kconfig

	if [ ! -d $dir_ap ]; then
		echo "Error! [$dir_ap] doesn't exist."
		exit 1
	fi

	#if [ ! -d $dir_sta ]; then
	#	echo "Error! [$dir_sta] doesn't exist."
	#	exit 1
	#fi

	if [ "$1" == "auto_build" ]; then
		if [ -d ../$dir_main\_auto_build ]; then
			rm -rf ../$dir_main\_auto_build
		fi
		if [ -d ../$dir_ap\_auto_build ]; then
			rm -rf 	../$dir_ap\_auto_build
		fi
		#if [ -d ../$dir_sta\_auto_build ]; then
		#	rm -rf 	../$dir_sta\_auto_build
		#fi
		mv $dir_main ../$dir_main\_auto_build
		mv $dir_ap ../$dir_ap\_auto_build
		#mv $dir_ap ../$dir_sta\_auto_build
		cd ../../
		#rm -rf release 
	else
		rm $dir_main/embedded/auto_build.sh
		rm $dir_main/embedded/auto_build_7628_7612.sh
		tar -jcvf  $package_name\.tar.bz2 $dir_main $dir_ap
		#tar -jcvf  $package_name\.tar.bz2 $dir_main $dir_ap $dir_sta
		#rm -rf $dir_main $dir_ap $dir_sta
	fi

############################
