obj-m := reg_kmalloc.o

KDIR := /lib/modules/`uname -r`/build/
PWD := $(shell pwd)

default:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
