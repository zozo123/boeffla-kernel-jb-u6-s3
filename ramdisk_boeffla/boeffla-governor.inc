# change governor to lulzactiveq or zzmoove (if not set to default)

if /sbin/busybox [ "`/sbin/busybox grep governor=lulz $BOEFFLA_CONFIG`" ]; then
  
	echo "lulzactiveq" > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor

	echo $(date) Governor set to lulzactiveq >> $BOEFFLA_LOGFILE

fi

if /sbin/busybox [ "`/sbin/busybox grep governor=zzmoove $BOEFFLA_CONFIG`" ]; then
  
	echo "zzmoove" > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor

	echo $(date) Governor set to zzmoove >> $BOEFFLA_LOGFILE

fi
