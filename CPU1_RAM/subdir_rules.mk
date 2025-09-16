################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
build-1298262865: ../InterleavedPSU.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/ccs2011/ccs/utils/sysconfig_1.24.0/sysconfig_cli.bat" --script "C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155/InterleavedPSU.syscfg" -o "syscfg" -s "C:/ti/C2000Ware_6_00_00_00/.metadata/sdk.json" -d "F280015x" -p "64PM" -r "F280015x_64PM" --context "system" --compiler ccs
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/board.c: build-1298262865 ../InterleavedPSU.syscfg
syscfg/board.h: build-1298262865
syscfg/board.cmd.genlibs: build-1298262865
syscfg/board.opt: build-1298262865
syscfg/board.json: build-1298262865
syscfg/pinmux.csv: build-1298262865
syscfg/epwm.dot: build-1298262865
syscfg/device.c: build-1298262865
syscfg/device.h: build-1298262865
syscfg/adc.dot: build-1298262865
syscfg/device_cmd.cmd: build-1298262865
syscfg/device_cmd.c: build-1298262865
syscfg/device_cmd.h: build-1298262865
syscfg/device_cmd.opt: build-1298262865
syscfg/device_cmd.cmd.genlibs: build-1298262865
syscfg/c2000ware_libraries.cmd.genlibs: build-1298262865
syscfg/c2000ware_libraries.opt: build-1298262865
syscfg/c2000ware_libraries.c: build-1298262865
syscfg/c2000ware_libraries.h: build-1298262865
syscfg/clocktree.h: build-1298262865
syscfg: build-1298262865

syscfg/%.obj: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --tmu_support=tmu0 -Ooff --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/headers/include" --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/common/include" --include_path="C:/ti/C2000Ware_6_00_00_00/driverlib/f280015x/driverlib/" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155" --include_path="C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/include" --define=DEBUG --define=RAM --define=_DUAL_HEADERS --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="syscfg/$(basename $(<F)).d_raw" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155/CPU1_RAM/syscfg" --obj_directory="syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

f280015x_codestartbranch.obj: C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/common/source/f280015x_codestartbranch.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --tmu_support=tmu0 -Ooff --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/headers/include" --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/common/include" --include_path="C:/ti/C2000Ware_6_00_00_00/driverlib/f280015x/driverlib/" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155" --include_path="C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/include" --define=DEBUG --define=RAM --define=_DUAL_HEADERS --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155/CPU1_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

DCL_clamp_C1.obj: C:/ti/C2000Ware_6_00_00_00/libraries/control/DCL/c28/source/DCL_clamp_C1.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --tmu_support=tmu0 -Ooff --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/headers/include" --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/common/include" --include_path="C:/ti/C2000Ware_6_00_00_00/driverlib/f280015x/driverlib/" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155" --include_path="C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/include" --define=DEBUG --define=RAM --define=_DUAL_HEADERS --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155/CPU1_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

DCL_DF11_C1.obj: C:/ti/C2000Ware_6_00_00_00/libraries/control/DCL/c28/source/DCL_DF11_C1.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --tmu_support=tmu0 -Ooff --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/headers/include" --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/common/include" --include_path="C:/ti/C2000Ware_6_00_00_00/driverlib/f280015x/driverlib/" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155" --include_path="C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/include" --define=DEBUG --define=RAM --define=_DUAL_HEADERS --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155/CPU1_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

DCL_DF13_C1.obj: C:/ti/C2000Ware_6_00_00_00/libraries/control/DCL/c28/source/DCL_DF13_C1.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --tmu_support=tmu0 -Ooff --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/headers/include" --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/common/include" --include_path="C:/ti/C2000Ware_6_00_00_00/driverlib/f280015x/driverlib/" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155" --include_path="C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/include" --define=DEBUG --define=RAM --define=_DUAL_HEADERS --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155/CPU1_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

DCL_DF13_C2C3.obj: C:/ti/C2000Ware_6_00_00_00/libraries/control/DCL/c28/source/DCL_DF13_C2C3.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --tmu_support=tmu0 -Ooff --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/headers/include" --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/common/include" --include_path="C:/ti/C2000Ware_6_00_00_00/driverlib/f280015x/driverlib/" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155" --include_path="C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/include" --define=DEBUG --define=RAM --define=_DUAL_HEADERS --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155/CPU1_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

DCL_DF22_C1.obj: C:/ti/C2000Ware_6_00_00_00/libraries/control/DCL/c28/source/DCL_DF22_C1.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --tmu_support=tmu0 -Ooff --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/headers/include" --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/common/include" --include_path="C:/ti/C2000Ware_6_00_00_00/driverlib/f280015x/driverlib/" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155" --include_path="C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/include" --define=DEBUG --define=RAM --define=_DUAL_HEADERS --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155/CPU1_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

DCL_DF22_C2C3.obj: C:/ti/C2000Ware_6_00_00_00/libraries/control/DCL/c28/source/DCL_DF22_C2C3.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --tmu_support=tmu0 -Ooff --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/headers/include" --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/common/include" --include_path="C:/ti/C2000Ware_6_00_00_00/driverlib/f280015x/driverlib/" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155" --include_path="C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/include" --define=DEBUG --define=RAM --define=_DUAL_HEADERS --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155/CPU1_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

DCL_DF23_C1.obj: C:/ti/C2000Ware_6_00_00_00/libraries/control/DCL/c28/source/DCL_DF23_C1.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --tmu_support=tmu0 -Ooff --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/headers/include" --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/common/include" --include_path="C:/ti/C2000Ware_6_00_00_00/driverlib/f280015x/driverlib/" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155" --include_path="C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/include" --define=DEBUG --define=RAM --define=_DUAL_HEADERS --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155/CPU1_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

DCL_DF23_C2C3.obj: C:/ti/C2000Ware_6_00_00_00/libraries/control/DCL/c28/source/DCL_DF23_C2C3.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --tmu_support=tmu0 -Ooff --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/headers/include" --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/common/include" --include_path="C:/ti/C2000Ware_6_00_00_00/driverlib/f280015x/driverlib/" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155" --include_path="C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/include" --define=DEBUG --define=RAM --define=_DUAL_HEADERS --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155/CPU1_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

DCL_error.obj: C:/ti/C2000Ware_6_00_00_00/libraries/control/DCL/c28/source/DCL_error.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --tmu_support=tmu0 -Ooff --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/headers/include" --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/common/include" --include_path="C:/ti/C2000Ware_6_00_00_00/driverlib/f280015x/driverlib/" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155" --include_path="C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/include" --define=DEBUG --define=RAM --define=_DUAL_HEADERS --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155/CPU1_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

DCL_futils.obj: C:/ti/C2000Ware_6_00_00_00/libraries/control/DCL/c28/source/DCL_futils.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --tmu_support=tmu0 -Ooff --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/headers/include" --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/common/include" --include_path="C:/ti/C2000Ware_6_00_00_00/driverlib/f280015x/driverlib/" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155" --include_path="C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/include" --define=DEBUG --define=RAM --define=_DUAL_HEADERS --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155/CPU1_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

DCL_PI_C1.obj: C:/ti/C2000Ware_6_00_00_00/libraries/control/DCL/c28/source/DCL_PI_C1.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --tmu_support=tmu0 -Ooff --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/headers/include" --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/common/include" --include_path="C:/ti/C2000Ware_6_00_00_00/driverlib/f280015x/driverlib/" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155" --include_path="C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/include" --define=DEBUG --define=RAM --define=_DUAL_HEADERS --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155/CPU1_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

DCL_PI_C4.obj: C:/ti/C2000Ware_6_00_00_00/libraries/control/DCL/c28/source/DCL_PI_C4.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --tmu_support=tmu0 -Ooff --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/headers/include" --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/common/include" --include_path="C:/ti/C2000Ware_6_00_00_00/driverlib/f280015x/driverlib/" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155" --include_path="C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/include" --define=DEBUG --define=RAM --define=_DUAL_HEADERS --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155/CPU1_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

DCL_PI_C7.obj: C:/ti/C2000Ware_6_00_00_00/libraries/control/DCL/c28/source/DCL_PI_C7.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --tmu_support=tmu0 -Ooff --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/headers/include" --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/common/include" --include_path="C:/ti/C2000Ware_6_00_00_00/driverlib/f280015x/driverlib/" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155" --include_path="C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/include" --define=DEBUG --define=RAM --define=_DUAL_HEADERS --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155/CPU1_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

DCL_PID_C1.obj: C:/ti/C2000Ware_6_00_00_00/libraries/control/DCL/c28/source/DCL_PID_C1.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --tmu_support=tmu0 -Ooff --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/headers/include" --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/common/include" --include_path="C:/ti/C2000Ware_6_00_00_00/driverlib/f280015x/driverlib/" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155" --include_path="C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/include" --define=DEBUG --define=RAM --define=_DUAL_HEADERS --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155/CPU1_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

DCL_PID_C4.obj: C:/ti/C2000Ware_6_00_00_00/libraries/control/DCL/c28/source/DCL_PID_C4.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --tmu_support=tmu0 -Ooff --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/headers/include" --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/common/include" --include_path="C:/ti/C2000Ware_6_00_00_00/driverlib/f280015x/driverlib/" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155" --include_path="C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/include" --define=DEBUG --define=RAM --define=_DUAL_HEADERS --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155/CPU1_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --tmu_support=tmu0 -Ooff --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/headers/include" --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/common/include" --include_path="C:/ti/C2000Ware_6_00_00_00/driverlib/f280015x/driverlib/" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155" --include_path="C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/include" --define=DEBUG --define=RAM --define=_DUAL_HEADERS --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155/CPU1_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

f280015x_globalvariabledefs.obj: C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/headers/source/f280015x_globalvariabledefs.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --tmu_support=tmu0 -Ooff --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/headers/include" --include_path="C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/common/include" --include_path="C:/ti/C2000Ware_6_00_00_00/driverlib/f280015x/driverlib/" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155" --include_path="C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/include" --define=DEBUG --define=RAM --define=_DUAL_HEADERS --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/arj/workspace_ccstheia/InterleavedPSU_EvalBoard_F2800155/CPU1_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


