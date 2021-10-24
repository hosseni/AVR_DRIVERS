################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
AMIT_M15_Keypad.lss \

FLASH_IMAGE += \
AMIT_M15_Keypad.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: AMIT_M15_Keypad.elf secondary-outputs

# Tool invocations
AMIT_M15_Keypad.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,AMIT_M15_Keypad.map -mmcu=atmega32 -o "AMIT_M15_Keypad.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

AMIT_M15_Keypad.lss: AMIT_M15_Keypad.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S AMIT_M15_Keypad.elf  >"AMIT_M15_Keypad.lss"
	@echo 'Finished building: $@'
	@echo ' '

AMIT_M15_Keypad.hex: AMIT_M15_Keypad.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex AMIT_M15_Keypad.elf  "AMIT_M15_Keypad.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: AMIT_M15_Keypad.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 AMIT_M15_Keypad.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) AMIT_M15_Keypad.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
