# change scheduler to deadline, noop, cfq or sio (if not set to default)

SCHEDULER=""

if /sbin/busybox [ "`/sbin/busybox grep scheduler=deadline $BOEFFLA_CONFIG`" ]; then
  SCHEDULER="deadline"
fi

if /sbin/busybox [ "`/sbin/busybox grep scheduler=noop $BOEFFLA_CONFIG`" ]; then
  SCHEDULER="noop"
fi

if /sbin/busybox [ "`/sbin/busybox grep scheduler=cfq $BOEFFLA_CONFIG`" ]; then
  SCHEDULER="cfq"
fi

if /sbin/busybox [ "`/sbin/busybox grep scheduler=sio $BOEFFLA_CONFIG`" ]; then
  SCHEDULER="sio"
fi

if [ ! -z $SCHEDULER ]; then
  echo "$SCHEDULER" > /sys/block/mmcblk0/queue/scheduler
  echo "$SCHEDULER" > /sys/block/mmcblk1/queue/scheduler
  echo $(date) Scheduler set to $SCHEDULER >> $BOEFFLA_LOGFILE
fi
