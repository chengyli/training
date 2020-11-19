#!/bin/bash

mkdir -p /tmp/test1
rm -f /tmp/test1/*
docker stop fio_test1;docker rm fio_test1

docker run -d --name fio_test1 --volume /tmp/test1:/tmp  registry/fio:v1 sleep 3600

sleep 2

CONTAINER_ID=$(sudo docker ps --format "{{.ID}}\t{{.Names}}" | grep -i fio_test1 | awk '{print $1}')
echo $CONTAINER_ID
CGROUP_CONTAINER_PATH=$(find /sys/fs/cgroup/blkio/ -name "*$CONTAINER_ID*")
echo $CGROUP_CONTAINER_PATH

# To get the device major and minor id from /dev for the device that /tmp/test1 is on.
echo "253:0 10485760" > $CGROUP_CONTAINER_PATH/blkio.throttle.read_bps_device
echo "253:0 10485760" > $CGROUP_CONTAINER_PATH/blkio.throttle.write_bps_device

docker exec fio_test1 fio -direct=1 -rw=write -ioengine=libaio -bs=4k -size=100MB -numjobs=1  -name=/tmp/fio_test1.log
docker exec fio_test1 fio -direct=1 -rw=read -ioengine=libaio -bs=4k -size=100MB -numjobs=1  -name=/tmp/fio_test1.log
