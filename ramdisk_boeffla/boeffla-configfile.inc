# check if config file exists and create a new one if not
if [ ! -f $BOEFFLA_CONFIG ] ; then

	echo "Boeffla-Kernel configuration" > $BOEFFLA_CONFIG
	echo "============================" >> $BOEFFLA_CONFIG
	echo " " >> $BOEFFLA_CONFIG

	# change file permissions to make file readable via /sdcard link as well
	chmod 666 $BOEFFLA_CONFIG

fi


# Now add all the required options that do not yet exists

# Tweaks

if ! /sbin/busybox [ "`/sbin/busybox grep ext4tweaks $BOEFFLA_CONFIG`" ]; then
	echo "ext4tweaks=on (on/off)" >> $BOEFFLA_CONFIG
	echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep sdcardtweaks $BOEFFLA_CONFIG`" ]; then
	echo "sdcardtweaks=on (on/off)" >> $BOEFFLA_CONFIG
	echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep systemtweaks $BOEFFLA_CONFIG`" ]; then
	echo "systemtweaks=on (on/off/smod/peg)" >> $BOEFFLA_CONFIG
	echo " " >> $BOEFFLA_CONFIG
fi


# Sharpness fix

if ! /sbin/busybox [ "`/sbin/busybox grep sharpness_fix $BOEFFLA_CONFIG`" ]; then
	echo "sharpness_fix=off (off/on)" >> $BOEFFLA_CONFIG
	echo " " >> $BOEFFLA_CONFIG
fi


# Undervolting

if ! /sbin/busybox [ "`/sbin/busybox grep cpu_undervolting $BOEFFLA_CONFIG`" ]; then
	echo "cpu_undervolting=off (off/25/50/75/100/light/medium/heavy)" >> $BOEFFLA_CONFIG
	echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep gpu_undervolting $BOEFFLA_CONFIG`" ]; then
	echo "gpu_undervolting=off (off/25/50/75/100/light/medium/heavy)" >> $BOEFFLA_CONFIG
	echo " " >> $BOEFFLA_CONFIG
fi


# Scheduler, governor, frequencies

if ! /sbin/busybox [ "`/sbin/busybox grep scheduler $BOEFFLA_CONFIG`" ]; then
	echo "scheduler=default (default/cfq/deadline/noop/sio/row/bfq)" >> $BOEFFLA_CONFIG
	echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep governor $BOEFFLA_CONFIG`" ]; then
	echo "governor=default (default/lulz/zzmoove)" >> $BOEFFLA_CONFIG
	echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep cpu_maxfreq $BOEFFLA_CONFIG`" ]; then
        echo "cpu_maxfreq=default (default/200...1400)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi


# Charging

if ! /sbin/busybox [ "`/sbin/busybox grep charge_ac $BOEFFLA_CONFIG`" ]; then
	echo "charge_ac=1100 (600...1200)" >> $BOEFFLA_CONFIG
	echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep charge_usb $BOEFFLA_CONFIG`" ]; then
	echo "charge_usb=475 (475...900)" >> $BOEFFLA_CONFIG
	echo " " >> $BOEFFLA_CONFIG
fi


# Boeffla-Sound

if ! /sbin/busybox [ "`/sbin/busybox grep sound_speaker_vol $BOEFFLA_CONFIG`" ]; then
        echo "sound_speaker_vol=default (default/57...63)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep sound_headphone_vol $BOEFFLA_CONFIG`" ]; then
        echo "sound_headphone_vol=default (default/45...63)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep sound_eq $BOEFFLA_CONFIG`" ]; then
        echo "sound_eq=off (off/bass-extreme/bass-treble/treble/classic/pleasant/eargasm/custom)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep sound_eq_custom_0100Hz $BOEFFLA_CONFIG`" ]; then
        echo "sound_eq_custom_0100Hz=0 (-12...12)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep sound_eq_custom_0300Hz $BOEFFLA_CONFIG`" ]; then
        echo "sound_eq_custom_0300Hz=0 (-12...12)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep sound_eq_custom_0875Hz $BOEFFLA_CONFIG`" ]; then
        echo "sound_eq_custom_0875Hz=0 (-12...12)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep sound_eq_custom_2400Hz $BOEFFLA_CONFIG`" ]; then
        echo "sound_eq_custom_2400Hz=0 (-12...12)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep sound_eq_custom_6900Hz $BOEFFLA_CONFIG`" ]; then
        echo "sound_eq_custom_6900Hz=0 (-12...12)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep sound_dac_direct $BOEFFLA_CONFIG`" ]; then
        echo "sound_dac_direct=off (off/on)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep sound_dac_oversampling $BOEFFLA_CONFIG`" ]; then
        echo "sound_dac_oversampling=off (off/on)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep sound_fll_tuning $BOEFFLA_CONFIG`" ]; then
        echo "sound_fll_tuning=off (off/on)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep sound_privacy_mode $BOEFFLA_CONFIG`" ]; then
        echo "sound_privacy_mode=off (off/on)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep sound_mic_mode $BOEFFLA_CONFIG`" ]; then
        echo "sound_mic_mode=default (default/concert/noisy/light)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi


# Auto root

if ! /sbin/busybox [ "`/sbin/busybox grep autoroot $BOEFFLA_CONFIG`" ]; then
	echo "autoroot=off (off/on)" >> $BOEFFLA_CONFIG
	echo " " >> $BOEFFLA_CONFIG
fi


# Configuration app
if ! /sbin/busybox [ "`/sbin/busybox grep boeffla_app $BOEFFLA_CONFIG`" ]; then
	echo "boeffla_app=on (on/off)" >> $BOEFFLA_CONFIG
	echo " " >> $BOEFFLA_CONFIG
fi


# Logging

if ! /sbin/busybox [ "`/sbin/busybox grep androidlogger $BOEFFLA_CONFIG`" ]; then
	echo "androidlogger=off (off/on)" >> $BOEFFLA_CONFIG
	echo " " >> $BOEFFLA_CONFIG
fi

if ! /sbin/busybox [ "`/sbin/busybox grep kernellogger $BOEFFLA_CONFIG`" ]; then
        echo "kernellogger=off (off/on)" >> $BOEFFLA_CONFIG
        echo " " >> $BOEFFLA_CONFIG
fi


# Clean up of changed options (where parameters were added)
/sbin/busybox sed "s/(default\/lulz)/(default\/lulz\/zzmoove)/g" $BOEFFLA_CONFIG -i
/sbin/busybox sed "s/(default\/55\/60\/62)/(default\/55\/57\/60\/62)/g" $BOEFFLA_CONFIG -i
/sbin/busybox sed "s/(default\/concert\/noisy)/(default\/concert\/noisy\/light)/g" $BOEFFLA_CONFIG -i
/sbin/busybox sed "s/(on\/off\/smod)/(on\/off\/smod\/peg)/g" $BOEFFLA_CONFIG -i
/sbin/busybox sed "s/(default\/cfq\/deadline\/noop\/sio)/(default\/cfq\/deadline\/noop\/sio\/row\/bfq)/g" $BOEFFLA_CONFIG -i
/sbin/busybox sed "s/(1000\/1100\/1200)/(600...1200)/g" $BOEFFLA_CONFIG -i
/sbin/busybox sed "s/(475\/700\/900)/(475...900)/g" $BOEFFLA_CONFIG -i
/sbin/busybox sed "s/(default\/55\/57\/60\/62)/(default\/45...63)/g" $BOEFFLA_CONFIG -i
/sbin/busybox sed "s/(default\/60\/63)/(default\/57...63)/g" $BOEFFLA_CONFIG -i
/sbin/busybox sed "s/(default\/1200\/1000\/800\/600\/400)/(default\/200...1400)/g" $BOEFFLA_CONFIG -i
/sbin/busybox sed "s/(off\/bass-extreme\/bass-treble\/treble\/classic\/pleasant\/eargasm)/(off\/bass-extreme\/bass-treble\/treble\/classic\/pleasant\/eargasm\/custom)/g" $BOEFFLA_CONFIG -i

# Finally remove old options that are not required anymore
/sbin/busybox sed "/Config file version/d" $BOEFFLA_CONFIG -i
/sbin/busybox sed "/bus_undervolting/d" $BOEFFLA_CONFIG -i
/sbin/busybox sed "/sound_bypass_outmix/d" $BOEFFLA_CONFIG -i

