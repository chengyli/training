#!/bin/bash

mkdir -p /tmp/test1
docker stop fio_test1;docker rm fio_test1

docker run --name fio_test1 --volume /tmp/test1:/tmp  registry/fio:v1 fio -direct=1 -rw=write -ioengine=libaio -bs=4k -size=1G -numjobs=1  -name=/tmp/fio_test1.log

