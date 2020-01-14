################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
../ATMEGA32/main.asm 

OBJS += \
./ATMEGA32/main.o 

ASM_DEPS += \
./ATMEGA32/main.d 


# Each subdirectory must supply rules for building sources it contributes
ATMEGA32/%.o: ../ATMEGA32/%.asm
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Assembler'
	avr-gcc -x assembler-with-cpp -g3 -gdwarf-2 -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


