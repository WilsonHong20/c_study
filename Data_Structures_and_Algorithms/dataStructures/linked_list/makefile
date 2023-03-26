ARCH ?= x86
TARGET = dataStruct
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


$(BUILD_DIR)/$(TARGET): $(OBJS)
	$(CC) -g -c -o $@ $^ $(CFLAGS)  

$(BUILD_DIR)/%.o:$(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) -g  -o $@ $^  $(CFLAGS) 

#伪目标
.PHONY: clean cleanall a
#按架构删除
clean:
	rm -rf $(BUILD_DIR)
#全部删除
cleanall:
	rm -rf build_x86 build_arm
a :
	@echo $(SRC)
	@echo $(OBJS)
	@echo $(BUILD_DIR)
