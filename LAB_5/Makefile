CROSS_COMPILE=/opt/gcc-arm-9.2-2019.12-x86_64-arm-none-linux-gnueabihf/bin/arm-none-linux-gnueabihf-
ARCH=arm
KDIR=/home/kekemon/repos/linux-stable

ifneq ($(KERNELRELEASE),)
# kbuild part of makefile
obj-m   := hello.o
else
# normal makefile
KDIR ?= /lib/modules/`uname -r`/build

default:
	$(MAKE) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) -C $(KDIR) M=$$PWD
clean:
	$(MAKE) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) -C $(KDIR) M=$$PWD clean
endif
