ARCH ?= x86
TARGET = sha256
BUILD_DIR := build_$(ARCH)
SRC := sha256.c main.c
OBJS := sha256.o
CFLAGS := -I.

ifeq ($(ARCH),x86)
	CC := gcc
else
	CC := arm-linux-gnueabihf-gcc
endif




@(TARGET):
	@mkdir -p $(BUILD_DIR)
	gcc -g -c -o $(BUILD_DIR)/$(TARGET).o $(SRC) $(CFLAGS)
	gcc -g -o  $(BUILD_DIR)/$(TARGET) $(BUILD_DIR)/$(TARGET).o 



#伪目标
.PHONY: clean cleanall 
#按架构删除
clean:
	rm -rf $(BUILD_DIR)
#全部删除
cleanall:
	rm -rf build_x86 build_arm
