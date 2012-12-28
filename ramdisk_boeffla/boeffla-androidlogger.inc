# load android logger when configured in boeffla config file or via boeffla tweaks app

if /sbin/busybox [ "`/sbin/busybox grep androidlogger=on $BOEFFLA_CONFIG`" ] || [ -f /data/boeffla-alogger ]; then
  /sbin/busybox insmod /lib/modules/logger.ko
  echo $(date) Android logger enabled >> $BOEFFLA_LOGFILE
fi


