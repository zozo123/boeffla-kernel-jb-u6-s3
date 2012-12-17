EFS_BACKUP_INT="/data/media/efs.tar.gz"
EFS_BACKUP_EXT="/storage/extSdCard/efs.tar.gz"

if [ ! -f $EFS_BACKUP_INT ] && [ ! -f $EFS_BACKUP_EXT ]; then

	/sbin/busybox tar cvz -f $EFS_BACKUP_INT /efs
	/sbin/busybox chmod 666 $EFS_BACKUP_INT
	/sbin/busybox mv $EFS_BACKUP_INT $EFS_BACKUP_EXT

	echo $(date) EFS Backup: Not found, now creating one >> $BOEFFLA_LOGFILE

fi
