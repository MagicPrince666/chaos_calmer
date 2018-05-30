#export STAGING_DIR = /Volumes/WPJ342/chaos_calmer/openwrt/staging_dir/toolchain-mips_34kc_gcc-4.8-linaro_uClibc-0.9.33.2/bin/

#CROSS_COMPILE ?= /Volumes/WPJ342/chaos_calmer/staging_dir/toolchain-mips_34kc_gcc-4.8-linaro_uClibc-0.9.33.2/bin/mips-openwrt-linux-uclibc-
#CXX = $(CROSS_COMPILE)g++

TARGET	= mjpg_rec 

DIR		= . 
INC		= -I. 
CFLAGS	= -g -Wall

OBJPATH	= .

FILES	= $(foreach dir,$(DIR),$(wildcard $(dir)/*.cpp))

OBJS	= $(patsubst %.cpp,%.o,$(FILES))

all:$(OBJS) $(TARGET)

$(OBJS):%.o:%.cpp
	$(CXX) $(CFLAGS) $(INC) -c -o $(OBJPATH)/$(notdir $@) $< 

$(TARGET):$(OBJPATH)
	$(CXX) -o $@ $(OBJPATH)/*.o

clean:
	-rm $(OBJPATH)/*.o
	-rm $(TARGET)