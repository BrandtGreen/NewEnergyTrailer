################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/System/Vehicle/VehCo.c 

OBJS += \
./src/System/Vehicle/VehCo.o 

C_DEPS += \
./src/System/Vehicle/VehCo.d 


# Each subdirectory must supply rules for building sources it contributes
src/System/Vehicle/%.o: ../src/System/Vehicle/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: TriCore C Compiler'
	"$(TRICORE_TOOLS)/bin/tricore-gcc" -c -I"D:\03_Development\Trailer\10_VCU_Debug\01_VehicleControl\src\HardwareLib" -I"D:\03_Development\Trailer\10_VCU_Debug\01_VehicleControl\src\RTE\stub" -I"D:\03_Development\Trailer\10_VCU_Debug\01_VehicleControl\src" -I"D:\03_Development\Trailer\10_VCU_Debug\01_VehicleControl\src\Global" -I"D:\03_Development\Trailer\10_VCU_Debug\01_VehicleControl\src\EOL" -I"D:\03_Development\Trailer\10_VCU_Debug\01_VehicleControl\src\System" -I"D:\03_Development\Trailer\10_VCU_Debug\01_VehicleControl\src\System\Vehicle" -I"D:\03_Development\Trailer\10_VCU_Debug\01_VehicleControl\src\System\Vehicle\Communication" -I"D:\03_Development\Trailer\10_VCU_Debug\01_VehicleControl\src\System\Vehicle\UDS" -fno-common -Os -g3 -W -Wall -Wextra -Wdiv-by-zero -Warray-bounds -Wcast-align -Wignored-qualifiers -Wformat -Wformat-security -fshort-double -mcpu=tc23xx -mversion-info -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


