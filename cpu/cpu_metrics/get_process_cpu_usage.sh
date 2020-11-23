#!/bin/bash

./threads-cpu 2 &
pid=$!
echo $pid
sleep 2

cat /proc/$pid/stat
sleep 1
cat /proc/$pid/stat
