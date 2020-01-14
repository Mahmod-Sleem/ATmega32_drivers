################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include LCD/subdir.mk
-include GPIO/subdir.mk
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
KEYPAD__deiver.lss \

FLASH_IMAGE += \
KEYPAD__deiver.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: KEYPAD__deiver.elf secondary-outputs

# Tool invocations
KEYPAD__deiver.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,KEYPAD__deiver.map -mmcu=atmega32 -o "KEYPAD__deiver.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

KEYPAD__deiver.lss: KEYPAD__deiver.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S KEYPAD__deiver.elf  >"KEYPAD__deiver.lss"
	@echo 'Finished building: $@'
	@echo ' '

KEYPAD__deiver.hex: KEYPAD__deiver.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex KEYPAD__deiver.elf  "KEYPAD__deiver.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: KEYPAD__deiver.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 KEYPAD__deiver.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) KEYPAD__deiver.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
