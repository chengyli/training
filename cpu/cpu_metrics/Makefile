all: image

image:
	docker build -t registry/cpu_metrics:v1 .
clean:
	docker rmi registry/cpu_metrics:v1
