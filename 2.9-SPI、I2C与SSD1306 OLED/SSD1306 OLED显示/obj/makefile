################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################
-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include User/subdir.mk
-include Startup/subdir.mk
-include Peripheral/src/subdir.mk
-include General_Files/drivers/subdir.mk
-include General_Files/subdir.mk
-include Debug/subdir.mk
-include Core/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
SSD1306 OLED显示.hex \

SECONDARY_LIST += \
SSD1306 OLED显示.lst \

SECONDARY_SIZE += \
SSD1306 OLED显示.siz \


# All Target
all: 
	$(MAKE) --no-print-directory main-build 

main-build: SSD1306 OLED显示.elf secondary-outputs

# Tool invocations
SSD1306 OLED显示.elf: $(OBJS) $(USER_OBJS)
	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -g -T "i:/programming/CH32/WorkSpace/1.3长短按键检测/2.9-SPI、I2C与SSD1306 OLED/SSD1306 OLED显示/Ld/Link.ld" -nostartfiles -Xlinker --gc-sections -Wl,-Map,"SSD1306 OLED显示.map" --specs=nano.specs --specs=nosys.specs -o "SSD1306 OLED显示.elf" $(OBJS) $(USER_OBJS) $(LIBS)
SSD1306 OLED显示.hex: SSD1306 OLED显示.elf
	@	riscv-none-embed-objcopy -O ihex "SSD1306 OLED显示.elf" "SSD1306 OLED显示.hex"
SSD1306 OLED显示.lst: SSD1306 OLED显示.elf
	@	riscv-none-embed-objdump --all-headers --demangle --disassemble "SSD1306 OLED显示.elf" > "SSD1306 OLED显示.lst"
SSD1306 OLED显示.siz: SSD1306 OLED显示.elf
	riscv-none-embed-size --format=berkeley "SSD1306 OLED显示.elf"

# Other Targets
clean:
	-$(RM) $(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(S_DEPS)$(S_UPPER_DEPS)$(ASM_DEPS)$(ASM_UPPER_DEPS)$(C_DEPS) SSD1306 OLED显示.elf

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets