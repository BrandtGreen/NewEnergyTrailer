################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/System/Vehicle/UDS/subdir.mk
-include src/System/Vehicle/Communication/subdir.mk
-include src/System/Vehicle/subdir.mk
-include src/RTE/stub/subdir.mk
-include src/RTE/subdir.mk
-include src/EOL/subdir.mk
-include src/App/CELCmgr/g_code/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

#rebuild target
rebuild: clean all

# All Target
all: VehicleControl.elf

# Tool invocations
VehicleControl.elf: $(OBJS) $(USER_OBJS) $(ASM)
	@echo 'Building target: $@'
	@echo 'Invoking: TriCore C Linker'
	"$(TRICORE_TOOLS)/bin/tricore-gcc" -o  "VehicleControl.elf"  "startup.o" -nocrt0 -T"..\ld\Lcf_Gnuc.ld" "src\App\CELCmgr\g_code\SwcCELCmgr.o" "src\EOL\EOLData.o" "src\RTE\Rte.o" "src\RTE\stub\Rte_SwcCELCmgr.o" "src\System\Vehicle\Communication\CANNet.o" "src\System\Vehicle\UDS\UDSInterface.o" "src\System\Vehicle\VehCo.o" -mcpu=tc23xx -Wl,--no-warn-flags -L"D:\03_Development\Trailer\10_VCU_Debug\01_VehicleControl\src\HardwareLib" -lVehicleLib -Wl,-Map="$(basename $(notdir $@)).map" -Wl,--cref -fshort-double -Wl,--extmap="a"
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(PCP_S)$(EXECUTABLES)$(OBJS)$(C_DEPS)$(CPCP_DEPS) VehicleControl.elf
	-@echo ' '

post-build:
	-tricore-objcopy -O ihex VehicleControl.elf VehicleControl.hex
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
