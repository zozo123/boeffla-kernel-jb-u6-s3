if /sbin/busybox [ "`/sbin/busybox grep boeffla_app=off $BOEFFLA_CONFIG`" ]; then

	# If app is installed, deinstall it now from all folders + delete all settings
	if [ -f /system/app/BoefflaTweaks.apk ] || [ -f /data/app/BoefflaTweaks.apk ]; then

		/sbin/busybox mount -o remount,rw -t ext4 $SYSTEM_DEVICE /system

		/sbin/busybox rm /system/app/BoefflaTweaks.apk
		/sbin/busybox rm /data/app/BoefflaTweaks.apk
		/sbin/busybox rm /system/etc/init.d/*_bk*

		/sbin/busybox mount -o remount,ro -t ext4 $SYSTEM_DEVICE /system

		echo $(date) Boeffla app deinstalled >> $BOEFFLA_LOGFILE
	fi

else

	# If app is not installed, install it now to system app folder + delete all previous settings
	if [ ! -f /system/app/BoefflaTweaks.apk ] && [ ! -f /data/app/BoefflaTweaks.apk ]; then

		/sbin/busybox mount -o remount,rw -t ext4 $SYSTEM_DEVICE /system

		/sbin/busybox cp /res/app/BoefflaTweaks.apk /system/app/BoefflaTweaks.apk
		/sbin/busybox chown 0.0 /system/app/BoefflaTweaks.apk
		/sbin/busybox chmod 644 /system/app/BoefflaTweaks.apk
		/sbin/busybox rm /system/etc/init.d/*_bk*

		/sbin/busybox mount -o remount,ro -t ext4 $SYSTEM_DEVICE /system

		echo $(date) Boeffla app installed >> $BOEFFLA_LOGFILE
	fi
fi

