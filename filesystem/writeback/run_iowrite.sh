#!/bin/bash

docker stop test_iowrite;docker rm test_iowrite

docker run -d --name test_iowrite --volume /tmp/test1:/tmp  registry/iowrite:v1 sleep 3600

sleep 2

CONTAINER_ID=$(sudo docker ps --format "{{.ID}}\t{{.Names}}" | grep -i test_iowrite | awk '{print $1}')
echo $CONTAINER_ID
CGROUP_CONTAINER_PATH=$(find /sys/fs/cgroup/memory/ -name "*$CONTAINER_ID*")
echo $CGROUP_CONTAINER_PATH

echo "1073741824" > $CGROUP_CONTAINER_PATH/memory.limit_in_bytes

docker exec test_iowrite /mem_alloc 1000 &
sleep 20
docker exec test_iowrite /test_iowrite /tmp/test1.log /tmp/test1.copy &


