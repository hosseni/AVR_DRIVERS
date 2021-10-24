################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_PROG.c \
../Dio_Prog.c \
../ICU_TIMER1.c \
../LCD_PROG.c \
../main.c 

OBJS += \
./ADC_PROG.o \
./Dio_Prog.o \
./ICU_TIMER1.o \
./LCD_PROG.o \
./main.o 

C_DEPS += \
./ADC_PROG.d \
./Dio_Prog.d \
./ICU_TIMER1.d \
./LCD_PROG.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


