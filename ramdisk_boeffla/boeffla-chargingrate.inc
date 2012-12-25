# Initialize variables
AC_RATE=""
USB_RATE=""


# AC charging rate
if /sbin/busybox [ "`/sbin/busybox grep charge_ac=1000 $BOEFFLA_CONFIG`" ]; then
  AC_RATE="1000"
fi

if /sbin/busybox [ "`/sbin/busybox grep charge_ac=1100 $BOEFFLA_CONFIG`" ]; then
  AC_RATE="1100"
fi

if /sbin/busybox [ "`/sbin/busybox grep charge_ac=1200 $BOEFFLA_CONFIG`" ]; then
  AC_RATE="1200"
fi


# USB charging rate
if /sbin/busybox [ "`/sbin/busybox grep charge_usb=475 $BOEFFLA_CONFIG`" ]; then
  USB_RATE="475"
fi

if /sbin/busybox [ "`/sbin/busybox grep charge_usb=700 $BOEFFLA_CONFIG`" ]; then
  USB_RATE="700"
fi

if /sbin/busybox [ "`/sbin/busybox grep charge_usb=900 $BOEFFLA_CONFIG`" ]; then
  USB_RATE="900"
fi


# Only apply values if both valid
if [ ! -z $AC_RATE ] && [ ! -z $USB_RATE ]; then
  echo "$AC_RATE $USB_RATE" > /sys/kernel/charge_level/charge_level
  echo $(date) "AC charge rate set to $AC_RATE mA" >> $BOEFFLA_LOGFILE
  echo $(date) "USB charge rate set to $USB_RATE mA" >> $BOEFFLA_LOGFILE
fi

