KDIR	:= $(LINUX_DIR)
#KDIR	:= /Volumes/WPJ342/chaos_calmer/build_dir/target-mips_34kc_uClibc-0.9.33.2/linux-ar71xx_generic/linux-3.18.98
PWD	:= $(shell pwd)
ROOTDIR := $(PWD)/modules

# Default architecture is MIPS
ARC 	:= $(LINUX_KARCH) 
CROSS_CC := $(TARGET_CROSS)
#CROSS_CC :=/Volumes/WPJ342/chaos_calmer/staging_dir/toolchain-mips_34kc_gcc-4.8-linaro_uClibc-0.9.33.2/bin/mips-openwrt-linux-uclibc-


export KDIR
export ROOTDIR
export CROSS_CC

DEBUG = 0

all: wasp

wasp:
	@echo Making art module for Atheros wasp based design.
	make ARCH=$(ARC) AP83=1 WASP=1 DEBUG=$(DEBUG) CROSS_COMPILE=$(CROSS_CC) -C $(KDIR) M=$(PWD)/modules modules

clean:
	cd modules && make clean
