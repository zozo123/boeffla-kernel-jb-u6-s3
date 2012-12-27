# Initialize variables and read settings for AC and USB charge rates
AC_RATE=""
AC_RATE=$(/sbin/busybox sed -n -e 's/.*charge_ac=\(.*\)(.*/\1/p' $BOEFFLA_CONFIG)
USB_RATE=""
USB_RATE=$(/sbin/busybox sed -n -e 's/.*charge_usb=\(.*\)(.*/\1/p' $BOEFFLA_CONFIG)

# Only apply values if both valid
if [ "${AC_RATE:-0}" -ge 600 ] && [ "${AC_RATE:-0}" -le 1200 ] && [ "${USB_RATE:-0}" -ge 475 ] && [ "${USB_RATE:-0}" -le 900 ]; then
  echo "$AC_RATE $USB_RATE" > /sys/kernel/charge_level/charge_level
  echo $(date) "AC charge rate set to $AC_RATE mA" >> $BOEFFLA_LOGFILE
  echo $(date) "USB charge rate set to $USB_RATE mA" >> $BOEFFLA_LOGFILE
fi

