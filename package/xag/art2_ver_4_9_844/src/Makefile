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
	@echo Making generic AP art module build. This build target is used for 3rd party AP processor. 
	make ARCH=$(ARC) PB42=1 CFG_64BIT=0 DEBUG=$(DEBUG) CROSS_COMPILE=$(CROSS_CC) -C $(KDIR) M=$(PWD)/modules modules

akronite:
	@echo Making Akronite AP art module build.
	make ARCH=$(ARC) PB42=1 CFG_64BIT=0 DEBUG=$(DEBUG) CROSS_COMPILE=$(CROSS_CC) -C $(KDIR) M=$(PWD)/modules modules

hydra:
	@echo Making art module for Atheros hydra based design.
	make ARCH=$(ARC) PB42=1 CFG_64BIT=0 DEBUG=$(DEBUG) CROSS_COMPILE=$(CROSS_CC) -C $(KDIR) M=$(PWD)/modules modules

howl:
	@echo Making art module for Atheros howl based design.
	make ARCH=$(ARC) AP83=1 CFG_64BIT=0 DEBUG=$(DEBUG) CROSS_COMPILE=$(CROSS_CC) -C $(KDIR) M=$(PWD)/modules modules

python:
	@echo Making art module for Atheros python based design.
	make ARCH=$(ARC) PYTHON_EMU=1 CFG_64BIT=0 DEBUG=$(DEBUG) CROSS_COMPILE=$(CROSS_CC) -C $(KDIR) M=$(PWD)/modules modules

wasp:
	@echo Making art module for Atheros wasp based design.
	make ARCH=$(ARC) AP83=1 WASP=1 CFG_64BIT=0 DEBUG=$(DEBUG) CROSS_COMPILE=$(CROSS_CC) -C $(KDIR) M=$(PWD)/modules modules
	
honeybee:
	@echo Making art module for Atheros wasp based design.
	make ARCH=$(ARC) AP83=1 WASP=1 CFG_64BIT=0 DEBUG=$(DEBUG) CROSS_COMPILE=$(CROSS_CC) -C $(KDIR) M=$(PWD)/modules modules	

wasp_osprey:
	@echo Making art module for Atheros wasp-osprey DBSC based design.
	make ARCH=$(ARC) AP83=1 WASP=1 CFG_64BIT=0 PYTHON_EMU=1 WASP_OSPREY=1 DEBUG=$(DEBUG) CROSS_COMPILE=$(CROSS_CC) -C $(KDIR) M=$(PWD)/modules modules

scorpion:
	@echo Making art module for Atheros wasp based design.
	make ARCH=$(ARC) AP83=1 WASP=1 CFG_64BIT=0 DEBUG=$(DEBUG) CROSS_COMPILE=$(CROSS_CC) -C $(KDIR) M=$(PWD)/modules modules

scorpion_pci:
	@echo Making art module for Atheros Scorpion-peacock_pci slot 1 or 2 DBSC based design.
	make ARCH=$(ARC) AP83=1 WASP=1 CFG_64BIT=0 PYTHON_EMU=1 WASP_OSPREY=1 DEBUG=$(DEBUG) CROSS_COMPILE=$(CROSS_CC) -C $(KDIR) M=$(PWD)/modules modules

dragonfly:
	@echo Making art module for Atheros wasp based design.
	make ARCH=$(ARC) AP83=1 WASP=1 CFG_64BIT=0 DEBUG=$(DEBUG) CROSS_COMPILE=$(CROSS_CC) -C $(KDIR) M=$(PWD)/modules modules

dragonfly_pci:
	@echo Making art module for Atheros dragonfly_pci slot 1 based design.
	make ARCH=$(ARC) AP83=1 WASP=1 CFG_64BIT=0 PYTHON_EMU=1 WASP_OSPREY=1 DEBUG=$(DEBUG) CROSS_COMPILE=$(CROSS_CC) -C $(KDIR) M=$(PWD)/modules modules

dual_pcie:
	@echo Making art module for Dual Pcie design
	make ARCH=$(ARC) PB42=1 DUAL_PCIE=1 DEBUG=$(DEBUG) CROSS_COMPILE=$(CROSS_CC) -C $(KDIR) M=$(PWD)/modules modules

clean:
	cd modules && make clean
