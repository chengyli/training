#!/bin/bash

mkdir -p  /tmp/xfs_prjquota
xfs_quota -x -c 'project -s -p /tmp/xfs_prjquota 101' /

xfs_quota -x -c 'limit -p bhard=10m 101' /
