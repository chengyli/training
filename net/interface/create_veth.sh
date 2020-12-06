#!/bin/bash

#unshare --net bash
#pid=$(echo $$)
docker stop if-test;docker rm if-test
docker run -d --name if-test --network none centos:8.1.1911 sleep 36000
pid=$(ps -ef | grep "sleep 36000" | grep -v grep | awk '{print $2}')
echo $pid
ln -s /proc/$pid/ns/net /var/run/netns/$pid
# Create a pair of veth interfaces
ip link add name veth_host type veth peer name veth_container
# Put one of them in the new net ns
ip link set veth_container netns $pid

# In the container, setup veth_container
ip netns exec $pid ip link set veth_container name eth0
ip netns exec $pid ip addr add 172.17.1.2/16 dev eth0
ip netns exec $pid ip link set eth0 up
ip netns exec $pid ip route add default via 172.17.0.1

# In the host, set veth_host up
ip link set veth_host up

#ip link set veth_host master docker0
