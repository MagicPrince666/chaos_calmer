EXTRA_CFLAGS += -I$(PWD)/modules/include  -DPCI_BUS -D__KERNEL__ -DMODULE 
IX_CFLAGS += -I$(ROOTDIR)

ifeq ($(PB42),1)
EXTRA_CFLAGS += -DOWL_PB42
EXTRA_CFLAGS += -DCFG_64BIT=1
endif

ifeq ($(PYTHON_EMU),1)
EXTRA_CFLAGS += -DPYTHON_EMU
endif

ifeq ($(DEBUG),1)
EXTRA_CFLAGS += -DDK_DEBUG
endif

ifeq ($(AP83),1)
EXTRA_CFLAGS += -DAP83
endif

ifeq ($(WASP),1)
EXTRA_CFLAGS += -DAP83
EXTRA_CFLAGS += -DWASP
endif

ifeq ($(WASP_OSPREY),1)
EXTRA_CFLAGS += -DWASP_OSPREY
endif

ifeq ($(HORNET),1)
EXTRA_CFLAGS += -DAP83
EXTRA_CFLAGS += -DHORNET
endif

ifeq ($(OCTEON),1)
EXTRA_CFLAGS += -DOCTEON
endif

obj-${CONFIG_QCA_ART_2_23} := art.o
art-objs := dk_func.o client.o main.o dk_pci_bus.o dk_isr.o dk_event.o

clean:
	rm -rf *.o *.ko .*.cmd *mod.c *.symvers *.order .tmp_versions

