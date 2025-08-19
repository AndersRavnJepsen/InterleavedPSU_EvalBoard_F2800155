################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS

GEN_OPTS__FLAG := --cmd_file="syscfg/board.opt" --cmd_file="syscfg/c2000ware_libraries.opt" 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./syscfg/board.obj" \
"./syscfg/device.obj" \
"./syscfg/c2000ware_libraries.obj" \
"./f280015x_codestartbranch.obj" \
"./f280015x_globalvariabledefs.obj" \
"./main.obj" \
"../280015x_generic_ram_lnk.cmd" \
"C:/ti/C2000Ware_6_00_00_00/driverlib/f280015x/driverlib/ccs/Debug/driverlib.lib" \
"C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/headers/cmd/f280015x_headers_nonBIOS.cmd" \
$(GEN_CMDS__FLAG) \
-lc2000ware_libraries.cmd.genlibs \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
InterleavedPSU_EvalBoard_F2800155.out 

EXE_OUTPUTS__QUOTED += \
"InterleavedPSU_EvalBoard_F2800155.out" 


# All Target
all: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "InterleavedPSU_EvalBoard_F2800155.out"

# Tool invocations
InterleavedPSU_EvalBoard_F2800155.out: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: C2000 Linker'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --tmu_support=tmu0 -Ooff --define=DEBUG --define=RAM --define=_DUAL_HEADERS --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi -z -m"InterleavedPSU_EvalBoard_F2800155.map" --heap_size=0x100 --stack_size=0x200 --warn_sections -i"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/lib" -i"C:/ti/C2000Ware_6_00_00_00" -i"C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155/CPU1_RAM/syscfg" -i"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/include" --reread_libs --define=RAM --diag_wrap=off --display_error_number --xml_link_info="InterleavedPSU_EvalBoard_F2800155_linkInfo.xml" --entry_point=code_start --rom_model -o "InterleavedPSU_EvalBoard_F2800155.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(GEN_MISC_FILES__QUOTED)$(GEN_FILES__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "syscfg\board.obj" "syscfg\device.obj" "syscfg\c2000ware_libraries.obj" "f280015x_codestartbranch.obj" "f280015x_globalvariabledefs.obj" "main.obj" 
	-$(RM) "syscfg\board.d" "syscfg\device.d" "syscfg\c2000ware_libraries.d" "f280015x_globalvariabledefs.d" "main.d" 
	-$(RM) "f280015x_codestartbranch.d" 
	-$(RMDIR) $(GEN_MISC_DIRS__QUOTED)
	-@echo 'Finished clean'
	-@echo ' '

post-build:
	-if 0 == 1  mkdir "C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155/CPU1_RAM/diagrams"
	-if 0 == 1  C:/ti/ccs2011/ccs/tools/node/node.exe "C:/ti/C2000Ware_6_00_00_00/driverlib/.meta/generate_diagrams.js" "C:/ti/C2000Ware_6_00_00_00" "C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155/CPU1_RAM/diagrams" "C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155/CPU1_RAM/syscfg"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

