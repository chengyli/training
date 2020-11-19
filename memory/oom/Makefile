all: image

mem_alloc: mem-alloc/mem_alloc.c
	gcc -o mem-alloc/mem_alloc mem-alloc/mem_alloc.c
image: mem_alloc
	docker build -t registry/mem_alloc:v1 .
clean:
	rm mem-alloc/mem_alloc -f
	docker stop mem_alloc;docker rm mem_alloc;docker rmi registry/mem_alloc:v1
