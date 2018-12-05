KDIR	:= $(LINUX_DIR)
PWD	:= $(shell pwd)
ROOTDIR := $(PWD)/modules

ARC 	:= $(LINUX_KARCH) 
CROSS_CC := $(TARGET_CROSS)


export KDIR
export ROOTDIR
export CROSS_CC


# Default architecture is MIPS
KERNELARCH=mips

CROSS_CC=$(TARGET_CROSS)


export KDIR
export ROOTDIR
export CROSS_CC

all: wasp

default:
	@echo Making generic AP art module build. This build target is used for 3rd party AP processor. 
	make ARCH=$(ARC) PB42=1 DEBUG=$(DEBUG) CROSS_COMPILE=$(CROSS_CC) -C $(KDIR) M=$(PWD)/modules modules

hydra:
	@echo Making art module for Atheros hydra based design.
	make ARCH=$(ARC) PB42=1 DEBUG=$(DEBUG) CROSS_COMPILE=$(CROSS_CC) -C $(KDIR) M=$(PWD)/modules modules

howl:
	@echo Making art module for Atheros howl based design.
	make ARCH=$(ARC) AP83=1 DEBUG=$(DEBUG) CROSS_COMPILE=$(CROSS_CC) -C $(KDIR) M=$(PWD)/modules modules

python:
	@echo Making art module for Atheros python based design.
	make ARCH=$(ARC) PYTHON_EMU=1 DEBUG=$(DEBUG) CROSS_COMPILE=$(CROSS_CC) -C $(KDIR) M=$(PWD)/modules modules

wasp:
	@echo Making art module for Atheros wasp based design.
	make ARCH=$(ARC) AP83=1 WASP=1 DEBUG=$(DEBUG) CROSS_COMPILE=$(CROSS_CC) -C $(KDIR) M=$(PWD)/modules modules
	
honeybee:
	@echo Making art module for Atheros wasp based design.
	make ARCH=$(ARC) AP83=1 WASP=1 DEBUG=$(DEBUG) CROSS_COMPILE=$(CROSS_CC) -C $(KDIR) M=$(PWD)/modules modules	

wasp_osprey:
	@echo Making art module for Atheros wasp-osprey DBSC based design.
	make ARCH=$(ARC) AP83=1 WASP=1 PYTHON_EMU=1 WASP_OSPREY=1 DEBUG=$(DEBUG) CROSS_COMPILE=$(CROSS_CC) -C $(KDIR) M=$(PWD)/modules modules

scorpion:
	@echo Making art module for Atheros wasp based design.
	make ARCH=$(ARC) AP83=1 WASP=1 DEBUG=$(DEBUG) CROSS_COMPILE=$(CROSS_CC) -C $(KDIR) M=$(PWD)/modules modules

scorpion_pci:
	@echo Making art module for Atheros Scorpion-peacock_pci slot 1 or 2 DBSC based design.
	make ARCH=$(ARC) AP83=1 WASP=1 PYTHON_EMU=1 WASP_OSPREY=1 DEBUG=$(DEBUG) CROSS_COMPILE=$(CROSS_CC) -C $(KDIR) M=$(PWD)/modules modules

dragonfly:
	@echo Making art module for Atheros wasp based design.
	make ARCH=$(ARC) AP83=1 WASP=1 DEBUG=$(DEBUG) CROSS_COMPILE=$(CROSS_CC) -C $(KDIR) M=$(PWD)/modules modules

dragonfly_pci:
	@echo Making art module for Atheros dragonfly_pci slot 1 based design.
	make ARCH=$(ARC) AP83=1 WASP=1 PYTHON_EMU=1 WASP_OSPREY=1 DEBUG=$(DEBUG) CROSS_COMPILE=$(CROSS_CC) -C $(KDIR) M=$(PWD)/modules modules

p1020:
	@echo Making art module for Freescale powepc ref resigns
	make ARCH=$(ARC) PB42=1 P1020=1 DEBUG=$(DEBUG) CROSS_COMPILE=$(CROSS_CC) -C $(KDIR) M=$(PWD)/modules modules

clean:
	cd modules && make clean