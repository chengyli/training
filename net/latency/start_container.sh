#!/bin/bash
docker stop lat-test-1;docker rm lat-test-1

docker run --init --name lat-test-1 -d registry/latency-test:v1 /netserver -D

iptables -P FORWARD ACCEPT
echo 1 > /proc/sys/net/ipv4/ip_forward
