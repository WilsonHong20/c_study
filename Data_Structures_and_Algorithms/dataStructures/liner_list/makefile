ARCH ?= x86
TARGET = linerlist
BUILD_DIR := build_$(ARCH)
SRC_DIR := src
IDIR := include
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst %.c, $(BUILD_DIR)/%.o, $(notdir $(SRC)))
DEPS := $(wildcard $(IDIR))/*.h)
CFLAGS := $(patsubst %, -I%, $(IDIR))

ifeq ($(ARCH),x86)
CC := gcc
else
CC := arm-linux-gnueabihf-gcc
endif

@(TARGET):
	@mkdir -p $(BUILD_DIR)
	$(CC)  -c -o $(BUILD_DIR)/$(TARGET).o $(SRC) $(CFLAGS)
	$(CC)  -o  $(BUILD_DIR)/$(TARGET) $(BUILD_DIR)/$(TARGET).o $(CFLAGS)

.PHONY:build
build:
	@mkdir -p $(BUILD_DIR)
	$(CC) -g -c -o $(BUILD_DIR)/$(TARGET).o $(SRC) $(CFLAGS)
	$(CC) -g -o  $(BUILD_DIR)/$(TARGET) $(BUILD_DIR)/$(TARGET).o $(CFLAGS)
#伪目标
.PHONY: clean cleanall 
#按架构删除
clean:
	rm -rf $(BUILD_DIR)
#全部删除
cleanall:
	rm -rf build_x86 build_arm
