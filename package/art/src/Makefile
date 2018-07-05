#KDIR	:= /Volumes/WPJ342/chaos_calmer/build_dir/target-mips_34kc_uClibc-0.9.33.2/linux-ar71xx_generic/linux-3.18.98
KDIR	:= $(LINUX_KARCH)
PWD	:= $(shell pwd)
ROOTDIR := $(PWD)/modules
ARC 	:=mips 
CROSS_CC :=$(TARGET_CROSS)
#CROSS_CC :=/Volumes/WPJ342/chaos_calmer/staging_dir/toolchain-mips_34kc_gcc-4.8-linaro_uClibc-0.9.33.2/bin/mips-openwrt-linux-uclibc-

export KDIR
export ROOTDIR
export CROSS_CC

all: default

default:
	make ARCH=$(ARC) PB42=1 CROSS_COMPILE=$(CROSS_CC) -C $(KDIR) M=$(PWD)/modules modules

clean:
	cd modules && make clean
