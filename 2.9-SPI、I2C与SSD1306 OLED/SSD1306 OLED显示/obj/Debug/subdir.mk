################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Debug/debug.c 

C_DEPS += \
./Debug/debug.d 

OBJS += \
./Debug/debug.o 



# Each subdirectory must supply rules for building sources it contributes
Debug/%.o: ../Debug/%.c
	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -g -I"i:/programming/CH32/WorkSpace/1.3���̰������/2.9-SPI��I2C��SSD1306 OLED/SSD1306 OLED��ʾ/Debug" -I"i:/programming/CH32/WorkSpace/1.3���̰������/2.9-SPI��I2C��SSD1306 OLED/SSD1306 OLED��ʾ/Core" -I"i:/programming/CH32/WorkSpace/1.3���̰������/2.9-SPI��I2C��SSD1306 OLED/SSD1306 OLED��ʾ/User" -I"i:/programming/CH32/WorkSpace/1.3���̰������/2.9-SPI��I2C��SSD1306 OLED/SSD1306 OLED��ʾ/Peripheral/inc" -I"i:/programming/CH32/WorkSpace/1.3���̰������/2.9-SPI��I2C��SSD1306 OLED/SSD1306 OLED��ʾ/General_Files" -I"i:/programming/CH32/WorkSpace/1.3���̰������/2.9-SPI��I2C��SSD1306 OLED/SSD1306 OLED��ʾ/General_Files/drivers" -I"i:/programming/CH32/WorkSpace/1.3���̰������/2.9-SPI��I2C��SSD1306 OLED/SSD1306 OLED��ʾ/General_Files/apps" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
