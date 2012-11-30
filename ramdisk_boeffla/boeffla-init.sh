#!/sbin/busybox sh
#
# credits to various people, mainly hardcore and 3c


# define config file pathes, file variables and block devices
BOEFFLA_PATH="/data/media/boeffla-kernel"
BOEFFLA_CONFIG="$BOEFFLA_PATH/boeffla-kernel.conf"
BOEFFLA_LOGFILE="$BOEFFLA_PATH/boeffla-kernel.log"

SYSTEM_DEVICE="/dev/block/mmcblk0p9"
CACHE_DEVICE="/dev/block/mmcblk0p8"
DATA_DEVICE="/dev/block/mmcblk0p12"


# check if Boeffla kernel path exists and if so, execute config file
if [ -d "$BOEFFLA_PATH" ] ; then

	# check and create or update the configuration file
	. /sbin/boeffla-configfile.inc

	# maintain log file history
	rm $BOEFFLA_LOGFILE.3
	mv $BOEFFLA_LOGFILE.2 $BOEFFLA_LOGFILE.3
	mv $BOEFFLA_LOGFILE.1 $BOEFFLA_LOGFILE.2
	mv $BOEFFLA_LOGFILE $BOEFFLA_LOGFILE.1

	# Initialize the log file (chmod to make it readable also via /sdcard link)
	echo $(date) Boeffla-Kernel initialisation started > $BOEFFLA_LOGFILE
	/sbin/busybox chmod 666 $BOEFFLA_LOGFILE
	/sbin/busybox cat /proc/version >> $BOEFFLA_LOGFILE
	echo "=========================" >> $BOEFFLA_LOGFILE

else

	BOEFFLA_CONFIG=""
	BOEFFLA_LOGFILE=""

fi


# First thing to do: Android logger (otherwise does not work properly)
. /sbin/boeffla-androidlogger.inc

# Custom boot animation support
. /sbin/boeffla-bootanimation.inc


# Now wait for the rom to finish booting up
# (by checking for any android process)
while ! /sbin/busybox pgrep com.android ; do
  sleep 1
done
echo $(date) Rom boot trigger detected, continuing after 8 more seconds... >> $BOEFFLA_LOGFILE
sleep 8


# Kernel logger
. /sbin/boeffla-kernellogger.inc

# CPU max frequency
. /sbin/boeffla-cpumaxfrequency.inc

# Boeffla Sound
. /sbin/boeffla-sound.inc

# Turn off debugging for certain modules
. /sbin/boeffla-disabledebugging.inc

# Auto root support
. /sbin/boeffla-autoroot.inc

# Ext4 tweaks
. /sbin/boeffla-ext4.inc

# Sdcard buffer tweaks
. /sbin/boeffla-sdcard.inc

# System tweaks
. /sbin/boeffla-systemtweaks.inc

# CPU undervolting support
. /sbin/boeffla-cpuundervolt.inc

# GPU undervolting support
. /sbin/boeffla-gpuundervolt.inc

# AC and USB charging rate
. /sbin/boeffla-chargingrate.inc

sleep 2

# Governor
. /sbin/boeffla-governor.inc

# IO Scheduler
. /sbin/boeffla-scheduler.inc

# init.d support
. /sbin/boeffla-initd.inc

# Finished
echo $(date) Boeffla-Kernel initialisation completed >> $BOEFFLA_LOGFILE
