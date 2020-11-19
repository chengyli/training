all: app-test image
app-test: app-test.c
	gcc -o app-test app-test.c

image: app-test
	docker build -t registry/zombie-proc:v1 .
clean: 
	rm -f *.o app-test
	docker rmi registry/zombie-proc:v1
