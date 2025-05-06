################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../Startup/startup_ch32v30x_D8C.S 

S_UPPER_DEPS += \
./Startup/startup_ch32v30x_D8C.d 

OBJS += \
./Startup/startup_ch32v30x_D8C.o 



# Each subdirectory must supply rules for building sources it contributes
Startup/%.o: ../Startup/%.S
	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -g -x assembler -I"i:/programming/CH32/WorkSpace/1.3长短按键检测/2.9-SPI、I2C与SSD1306 OLED/SSD1306 OLED显示/Startup" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
