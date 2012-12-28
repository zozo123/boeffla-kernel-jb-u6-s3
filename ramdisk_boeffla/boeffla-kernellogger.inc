if /sbin/busybox [ "`/sbin/busybox grep kernellogger=on $BOEFFLA_CONFIG`" ] || [ -f /data/boeffla-klogger ]; then
  echo 1 > /sys/kernel/printk_mode/printk_mode

  echo $(date) Kernel logger enabled >> $BOEFFLA_LOGFILE

else

  echo 0 > /sys/kernel/printk_mode/printk_mode

fi

