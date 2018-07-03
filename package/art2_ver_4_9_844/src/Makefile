KDIR	:= $(LINUX_KARCH)
PWD	:= $(shell pwd)
ROOTDIR := $(PWD)/modules
ARC 	:=mips 
CROSS_CC :=$(TARGET_CROSS)
export KDIR
export ROOTDIR
export CROSS_CC

all: default

default:
	make ARCH=$(ARC) AP83=1 CROSS_COMPILE=$(CROSS_CC) -C $(KDIR) M=$(PWD)/modules modules

clean:
	cd modules && make clean
