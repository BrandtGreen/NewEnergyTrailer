################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../src/HardwareLib/crt0-tc2x.S 

OBJS += \
./src/HardwareLib/crt0-tc2x.o 


# Each subdirectory must supply rules for building sources it contributes
src/HardwareLib/%.o: ../src/HardwareLib/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: TriCore Assembler'
	"$(TRICORE_TOOLS)/bin/tricore-gcc" -c -I"D:\ECTEK\Project\P000\036\WorkSpace\VehicleControl\src\HardwareLib" -Wa,--gdwarf-2 -mcpu=tc23xx -Wa,--insn32-preferred -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


