if /sbin/busybox [ "`/sbin/busybox grep androidlogger=on $BOEFFLA_CONFIG`" ]; then
  /sbin/busybox insmod /lib/modules/logger.ko
  echo $(date) Android logger enabled >> $BOEFFLA_LOGFILE
fi
