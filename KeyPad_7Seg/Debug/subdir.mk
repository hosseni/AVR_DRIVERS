################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../7Seg_PROG.c \
../Dio_Prog.c \
../KeyPad_PROG.c \
../main.c 

OBJS += \
./7Seg_PROG.o \
./Dio_Prog.o \
./KeyPad_PROG.o \
./main.o 

C_DEPS += \
./7Seg_PROG.d \
./Dio_Prog.d \
./KeyPad_PROG.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


