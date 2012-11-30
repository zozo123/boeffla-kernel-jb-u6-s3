if /sbin/busybox [ "`/sbin/busybox grep gpu_undervolting=25 $BOEFFLA_CONFIG`" ]; then
  echo "875000 900000 975000 1025000" > /sys/class/misc/gpu_voltage_control/gpu_control
  echo $(date) GPU undervolting by -25mv applied >> $BOEFFLA_LOGFILE
fi

if /sbin/busybox [ "`/sbin/busybox grep gpu_undervolting=50 $BOEFFLA_CONFIG`" ]; then
  echo "850000 875000 950000 1000000" > /sys/class/misc/gpu_voltage_control/gpu_control
  echo $(date) GPU undervolting by -50mv applied >> $BOEFFLA_LOGFILE
fi

if /sbin/busybox [ "`/sbin/busybox grep gpu_undervolting=75 $BOEFFLA_CONFIG`" ]; then
  echo "825000 850000 925000 975000" > /sys/class/misc/gpu_voltage_control/gpu_control
  echo $(date) GPU undervolting by -75mv applied >> $BOEFFLA_LOGFILE
fi

if /sbin/busybox [ "`/sbin/busybox grep gpu_undervolting=100 $BOEFFLA_CONFIG`" ]; then
  echo "800000 825000 900000 950000" > /sys/class/misc/gpu_voltage_control/gpu_control
  echo $(date) GPU undervolting by -100mv applied >> $BOEFFLA_LOGFILE
fi

if /sbin/busybox [ "`/sbin/busybox grep gpu_undervolting=light $BOEFFLA_CONFIG`" ]; then
  echo "875000 900000 950000 1000000" > /sys/class/misc/gpu_voltage_control/gpu_control
  echo $(date) GPU undervolting light applied >> $BOEFFLA_LOGFILE
fi

if /sbin/busybox [ "`/sbin/busybox grep gpu_undervolting=medium $BOEFFLA_CONFIG`" ]; then
  echo "850000 875000 925000 975000" > /sys/class/misc/gpu_voltage_control/gpu_control
  echo $(date) GPU undervolting medium applied >> $BOEFFLA_LOGFILE
fi

if /sbin/busybox [ "`/sbin/busybox grep gpu_undervolting=heavy $BOEFFLA_CONFIG`" ]; then
  echo "825000 850000 900000 925000" > /sys/class/misc/gpu_voltage_control/gpu_control
  echo $(date) GPU undervolting heavy applied >> $BOEFFLA_LOGFILE
fi
