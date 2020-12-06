#!/bin/bash

docker stop lat-test-1;docker rm lat-test-1
docker stop lat-test-2;docker rm lat-test-2

docker run --init --name lat-test-1 --network none -d registry/latency-test:v1 sleep 36000

pid1=$(docker inspect lat-test-1 | grep -i Pid | head -n 1 | awk '{print $2}' | awk -F "," '{print $1}')
echo $pid1
ln -s /proc/$pid1/ns/net /var/run/netns/$pid1

ip link add link eth0 ipvt1 type ipvlan mode l2
ip link set dev ipvt1 netns $pid1

ip netns exec $pid1 ip link set ipvt1 name eth0
ip netns exec $pid1 ip addr add 172.17.3.2/16 dev eth0
ip netns exec $pid1 ip link set eth0 up

docker run --init --name lat-test-2 --network none -d registry/latency-test:v1 sleep 36000

pid2=$(docker inspect lat-test-2 | grep -i Pid | head -n 1 | awk '{print $2}' | awk -F "," '{print $1}')
echo $pid2
ln -s /proc/$pid2/ns/net /var/run/netns/$pid2

ip link add link eth0 ipvt2 type ipvlan mode l2
ip link set dev ipvt2 netns $pid2

ip netns exec $pid2 ip link set ipvt2 name eth0
ip netns exec $pid2 ip addr add 172.17.3.3/16 dev eth0
ip netns exec $pid2 ip link set eth0 up

