# Makefile - Build system for Sega Saturn Project

# Project name
PROJECT_NAME := batman_returns_saturn

# Toolchain commands
AS := sh-elf-as
LD := sh-elf-ld
OBJCOPY := sh-elf-objcopy
MKISOFS := mkisofs

# Directories
SRC_DIR := ../src/sh2
COMMON_DIR := ../src/common
Z80_DIR := ../src/z80
BUILD_DIR := .
BIN_DIR := ../bin

# Source files
SH2_SRC := $(SRC_DIR)/main_cpu.s \
           $(SRC_DIR)/audio.s \
           $(SRC_DIR)/dma.s \
           $(SRC_DIR)/game_logic.s \
           $(SRC_DIR)/graphics.s \
           $(SRC_DIR)/input.s \
           $(SRC_DIR)/vdp.s
Z80_SRC := $(Z80_DIR)/z80_code.s
COMMON_SRC := $(COMMON_DIR)/constants.inc \
              $(COMMON_DIR)/data_tables.inc \
              $(COMMON_DIR)/macros.inc \
              $(COMMON_DIR)/memory_map.inc

# Object files
SH2_OBJS := $(patsubst $(SRC_DIR)/%.s, $(BUILD_DIR)/%.o, $(SH2_SRC))
Z80_OBJS := $(patsubst $(Z80_DIR)/%.s, $(BUILD_DIR)/%.o, $(Z80_SRC))

# Output binary
OUTPUT_BIN := $(BIN_DIR)/$(PROJECT_NAME).bin

# Linker script
LDSCRIPT := linker_script.ld

# Build rules
all: $(OUTPUT_BIN) $(BIN_DIR)/$(PROJECT_NAME).iso

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.s $(COMMON_SRC)
	$(AS) -o $@ $<

$(BUILD_DIR)/%.o: $(Z80_DIR)/%.s
	$(AS) -o $@ $<

$(OUTPUT_BIN): $(SH2_OBJS) $(Z80_OBJS)
	$(LD) -T $(LDSCRIPT) -o $@ $(SH2_OBJS) $(Z80_OBJS)

$(BIN_DIR)/$(PROJECT_NAME).iso: $(OUTPUT_BIN)
	$(MKISOFS) -o $@ -V $(PROJECT_NAME) -l -J -R $(OUTPUT_BIN)

clean:
	rm -f $(BUILD_DIR)/*.o
	rm -f $(OUTPUT_BIN)
	rm -f $(BIN_DIR)/$(PROJECT_NAME).iso

.PHONY: all clean

