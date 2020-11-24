#!/bin/bash
fallocate -l 20G ./swapfile
dd if=/dev/zero of=./swapfile bs=1024 count=20971520
chmod 600 ./swapfile
mkswap ./swapfile
swapon swapfile
