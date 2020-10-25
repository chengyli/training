# Go related variables.
GOBASE=$(shell pwd)
GOPATH="$(GOBASE)/vendor:$(GOBASE)"
GOBIN=$(GOBASE)/bin
GOFILES=$(wildcard *.go)

all: go-init c-init-sig c-init-nosig

go-init: $(GOFILES)
	@GOPATH=$(GOPATH) GOBIN=$(GOBIN) go build -o ./bin/go-init $(GOFILES)

c-init-sig: c-init-sig.c
	gcc -o ./bin/c-init-sig c-init-sig.c

c-init-nosig: c-init-nosig.c
	gcc -o ./bin/c-init-nosig c-init-nosig.c

image: go-init c-init-sig c-init-nosig
	docker build -t registery/sig-proc:v1 .

clean:
	rm -f ./bin/*
	rm -f *.o
