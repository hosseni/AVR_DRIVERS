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
WDG_TIMER.lss \

FLASH_IMAGE += \
WDG_TIMER.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: WDG_TIMER.elf secondary-outputs

# Tool invocations
WDG_TIMER.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,WDG_TIMER.map -mmcu=atmega32 -o "WDG_TIMER.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

WDG_TIMER.lss: WDG_TIMER.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S WDG_TIMER.elf  >"WDG_TIMER.lss"
	@echo 'Finished building: $@'
	@echo ' '

WDG_TIMER.hex: WDG_TIMER.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex WDG_TIMER.elf  "WDG_TIMER.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: WDG_TIMER.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 WDG_TIMER.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) WDG_TIMER.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
