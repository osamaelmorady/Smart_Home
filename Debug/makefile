################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include TIM2/subdir.mk
-include TIM0/subdir.mk
-include LCD/subdir.mk
-include DIO/subdir.mk
-include ADC/subdir.mk
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
Lock_System.lss \

FLASH_IMAGE += \
Lock_System.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Lock_System.elf secondary-outputs

# Tool invocations
Lock_System.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Lock_System.map -mmcu=atmega32 -o "Lock_System.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Lock_System.lss: Lock_System.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Lock_System.elf  >"Lock_System.lss"
	@echo 'Finished building: $@'
	@echo ' '

Lock_System.hex: Lock_System.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Lock_System.elf  "Lock_System.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Lock_System.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Lock_System.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Lock_System.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
