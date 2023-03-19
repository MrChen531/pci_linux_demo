MODULE = dio_pci_drv
obj-m := $(MODULE).o

$(MODULE)-objs := \
	dio_pci.o \

KERNEL_VERS = $(shell uname -r)
KDIR := /lib/modules/$(KERNEL_VERS)/build/


all:
	make -C $(KDIR) M=$(PWD) modules

clean:
	rm -rf *.ko *.o *.mod.o *.mod.c *.symvers *.bak *.order
