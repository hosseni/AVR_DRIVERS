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
AMIT_LCD_TEST.lss \

FLASH_IMAGE += \
AMIT_LCD_TEST.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: AMIT_LCD_TEST.elf secondary-outputs

# Tool invocations
AMIT_LCD_TEST.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,AMIT_LCD_TEST.map -mmcu=atmega32 -o "AMIT_LCD_TEST.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

AMIT_LCD_TEST.lss: AMIT_LCD_TEST.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S AMIT_LCD_TEST.elf  >"AMIT_LCD_TEST.lss"
	@echo 'Finished building: $@'
	@echo ' '

AMIT_LCD_TEST.hex: AMIT_LCD_TEST.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex AMIT_LCD_TEST.elf  "AMIT_LCD_TEST.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: AMIT_LCD_TEST.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 AMIT_LCD_TEST.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) AMIT_LCD_TEST.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
