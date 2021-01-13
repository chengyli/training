# Go related variables.
GOBASE=$(shell pwd)
GOPATH="$(GOBASE)/vendor:$(GOBASE)"
GOBIN=$(GOBASE)/bin
GOFILES=$(wildcard *.go)

all: image

test-iowrite: $(GOFILES)
	@GOPATH=$(GOPATH) GOBIN=$(GOBIN) go build -o ./bin/test_iowrite $(GOFILES)


image:
	docker build -t registry/iowrite:v1 .

clean:
	rm -f ./bin/*
	rm -f *.o
	docker rmi registry/iowrite:v1

