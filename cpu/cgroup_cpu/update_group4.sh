#!/bin/bash

echo 350000 > /sys/fs/cgroup/cpu/group2/group4/cpu.cfs_quota_us
echo 3072 > /sys/fs/cgroup/cpu/group2/group4/cpu.shares
./threads-cpu/threads-cpu 4 &
echo $! > /sys/fs/cgroup/cpu/group2/group4/cgroup.procs

