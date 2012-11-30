# change max cpu frequency

if /sbin/busybox [ "`/sbin/busybox grep cpu_maxfreq=1200 $BOEFFLA_CONFIG`" ]; then
        echo "1200000" > /sys/devices/system/cpu/cpu0/cpufreq/scaling_max_freq
	echo $(date) Max CPU set to 1200 MHz >> $BOEFFLA_LOGFILE
fi

if /sbin/busybox [ "`/sbin/busybox grep cpu_maxfreq=1000 $BOEFFLA_CONFIG`" ]; then
        echo "1000000" > /sys/devices/system/cpu/cpu0/cpufreq/scaling_max_freq
        echo $(date) Max CPU set to 1000 MHz >> $BOEFFLA_LOGFILE
fi

if /sbin/busybox [ "`/sbin/busybox grep cpu_maxfreq=800 $BOEFFLA_CONFIG`" ]; then
        echo "800000" > /sys/devices/system/cpu/cpu0/cpufreq/scaling_max_freq
        echo $(date) Max CPU set to 800 MHz >> $BOEFFLA_LOGFILE
fi

if /sbin/busybox [ "`/sbin/busybox grep cpu_maxfreq=600 $BOEFFLA_CONFIG`" ]; then
        echo "600000" > /sys/devices/system/cpu/cpu0/cpufreq/scaling_max_freq
        echo $(date) Max CPU set to 600 MHz >> $BOEFFLA_LOGFILE
fi

if /sbin/busybox [ "`/sbin/busybox grep cpu_maxfreq=400 $BOEFFLA_CONFIG`" ]; then
        echo "400000" > /sys/devices/system/cpu/cpu0/cpufreq/scaling_max_freq
        echo $(date) Max CPU set to 400 MHz >> $BOEFFLA_LOGFILE
fi
