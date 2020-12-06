all: image

image:
	docker build -t registry/latency-test:v1 .
clean: 
	docker rmi registry/latency-test:v1
