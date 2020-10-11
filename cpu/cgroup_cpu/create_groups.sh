#!/bin/bash

mkdir -p /sys/fs/cgroup/cpu/group1
mkdir -p /sys/fs/cgroup/cpu/group2
mkdir -p /sys/fs/cgroup/cpu/group2/group3
mkdir -p /sys/fs/cgroup/cpu/group2/group4

make -C threads-cpu/

