if ! /sbin/busybox [ "`/sbin/busybox grep sdcardtweaks=off $BOEFFLA_CONFIG`" ]; then

	echo "256" > /sys/block/mmcblk0/bdi/read_ahead_kb
	echo "256" > /sys/block/mmcblk1/bdi/read_ahead_kb
	echo $(date) SDcard buffer tweaks applied >> $BOEFFLA_LOGFILE

fi
