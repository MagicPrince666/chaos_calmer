#export STAGING_DIR = /Volumes/WPJ342/chaos_calmer/openwrt/staging_dir/toolchain-mips_34kc_gcc-4.8-linaro_uClibc-0.9.33.2/bin/

#CROSS_COMPILE ?= /Volumes/WPJ342/chaos_calmer/staging_dir/toolchain-mips_34kc_gcc-4.8-linaro_uClibc-0.9.33.2/bin/mips-openwrt-linux-uclibc-
#CC = $(CROSS_COMPILE)gcc

TARGET	= h264_rec 

DIR		= .
INC		= -I.
CFLAGS	= -g -Wall

OBJPATH	= .

LDFLAGS := -lm -ldl -lrt

CFILES	= $(foreach dir,$(DIR),$(wildcard $(dir)/*.c))

COBJS	= $(patsubst %.c,%.o,$(CFILES))

all: $(COBJS) $(TARGET)


$(COBJS):%.o:%.c
	$(CC) $(CFLAGS) $(INC) -c -o $(OBJPATH)/$(notdir $@) $< 

$(TARGET):$(OBJPATH)
	$(CC) -o $@ $(OBJPATH)/*.o $(LDFLAGS)

clean:
	-rm $(OBJPATH)/*.o
	-rm $(TARGET)