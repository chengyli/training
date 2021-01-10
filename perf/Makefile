all: perf_test image

perf_test: perf_test.c
	gcc -o perf_test -fno-omit-frame-pointer perf_test.c

image: perf.tar.gz perf_test
	docker build -t registry/perf_test:v1 .
clean:
	rm -f perf_test
	rm -f *.o	
	docker rmi registry/perf_test:v1
