#!/bin/bash

echo 350000 > /sys/fs/cgroup/cpu/group1/cpu.cfs_quota_us
echo 1024 > /sys/fs/cgroup/cpu/group1/cpu.shares
./threads-cpu/threads-cpu 4 &
echo $! > /sys/fs/cgroup/cpu/group1/cgroup.procs
