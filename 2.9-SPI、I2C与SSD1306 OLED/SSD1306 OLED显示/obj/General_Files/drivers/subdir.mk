################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../General_Files/drivers/I2C_soft.c \
../General_Files/drivers/KeyPress.c \
../General_Files/drivers/SSD1306.c 

C_DEPS += \
./General_Files/drivers/I2C_soft.d \
./General_Files/drivers/KeyPress.d \
./General_Files/drivers/SSD1306.d 

OBJS += \
./General_Files/drivers/I2C_soft.o \
./General_Files/drivers/KeyPress.o \
./General_Files/drivers/SSD1306.o 



# Each subdirectory must supply rules for building sources it contributes
General_Files/drivers/%.o: ../General_Files/drivers/%.c
	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -g -I"i:/programming/CH32/WorkSpace/1.3³¤¶Ì°´¼ü¼ì²â/2.9-SPI¡¢I2CÓëSSD1306 OLED/SSD1306 OLEDÏÔÊ¾/Debug" -I"i:/programming/CH32/WorkSpace/1.3³¤¶Ì°´¼ü¼ì²â/2.9-SPI¡¢I2CÓëSSD1306 OLED/SSD1306 OLEDÏÔÊ¾/Core" -I"i:/programming/CH32/WorkSpace/1.3³¤¶Ì°´¼ü¼ì²â/2.9-SPI¡¢I2CÓëSSD1306 OLED/SSD1306 OLEDÏÔÊ¾/User" -I"i:/programming/CH32/WorkSpace/1.3³¤¶Ì°´¼ü¼ì²â/2.9-SPI¡¢I2CÓëSSD1306 OLED/SSD1306 OLEDÏÔÊ¾/Peripheral/inc" -I"i:/programming/CH32/WorkSpace/1.3³¤¶Ì°´¼ü¼ì²â/2.9-SPI¡¢I2CÓëSSD1306 OLED/SSD1306 OLEDÏÔÊ¾/General_Files" -I"i:/programming/CH32/WorkSpace/1.3³¤¶Ì°´¼ü¼ì²â/2.9-SPI¡¢I2CÓëSSD1306 OLED/SSD1306 OLEDÏÔÊ¾/General_Files/drivers" -I"i:/programming/CH32/WorkSpace/1.3³¤¶Ì°´¼ü¼ì²â/2.9-SPI¡¢I2CÓëSSD1306 OLED/SSD1306 OLEDÏÔÊ¾/General_Files/apps" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
