# Run container

```
echo -1 > /proc/sys/kernel/perf_event_paranoid
docker run --rm -it --security-opt seccomp=unconfined registry/perf_test:v1 bash
```
