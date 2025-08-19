################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
CMD_SRCS += \
../280015x_generic_ram_lnk.cmd \
C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/headers/cmd/f280015x_headers_nonBIOS.cmd 

SYSCFG_SRCS += \
../InterleavedPSU.syscfg 

LIB_SRCS += \
C:/ti/C2000Ware_6_00_00_00/driverlib/f280015x/driverlib/ccs/Debug/driverlib.lib 

ASM_SRCS += \
C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/common/source/f280015x_codestartbranch.asm 

C_SRCS += \
./syscfg/board.c \
./syscfg/device.c \
./syscfg/c2000ware_libraries.c \
C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/headers/source/f280015x_globalvariabledefs.c \
../main.c 

GEN_FILES += \
./syscfg/board.c \
./syscfg/board.opt \
./syscfg/device.c \
./syscfg/c2000ware_libraries.opt \
./syscfg/c2000ware_libraries.c 

GEN_MISC_DIRS += \
./syscfg 

C_DEPS += \
./syscfg/board.d \
./syscfg/device.d \
./syscfg/c2000ware_libraries.d \
./f280015x_globalvariabledefs.d \
./main.d 

GEN_OPTS += \
./syscfg/board.opt \
./syscfg/c2000ware_libraries.opt 

OBJS += \
./syscfg/board.obj \
./syscfg/device.obj \
./syscfg/c2000ware_libraries.obj \
./f280015x_codestartbranch.obj \
./f280015x_globalvariabledefs.obj \
./main.obj 

ASM_DEPS += \
./f280015x_codestartbranch.d 

GEN_MISC_FILES += \
./syscfg/board.h \
./syscfg/board.cmd.genlibs \
./syscfg/board.json \
./syscfg/pinmux.csv \
./syscfg/device.h \
./syscfg/c2000ware_libraries.cmd.genlibs \
./syscfg/c2000ware_libraries.h \
./syscfg/clocktree.h 

GEN_MISC_DIRS__QUOTED += \
"syscfg" 

OBJS__QUOTED += \
"syscfg\board.obj" \
"syscfg\device.obj" \
"syscfg\c2000ware_libraries.obj" \
"f280015x_codestartbranch.obj" \
"f280015x_globalvariabledefs.obj" \
"main.obj" 

GEN_MISC_FILES__QUOTED += \
"syscfg\board.h" \
"syscfg\board.cmd.genlibs" \
"syscfg\board.json" \
"syscfg\pinmux.csv" \
"syscfg\device.h" \
"syscfg\c2000ware_libraries.cmd.genlibs" \
"syscfg\c2000ware_libraries.h" \
"syscfg\clocktree.h" 

C_DEPS__QUOTED += \
"syscfg\board.d" \
"syscfg\device.d" \
"syscfg\c2000ware_libraries.d" \
"f280015x_globalvariabledefs.d" \
"main.d" 

GEN_FILES__QUOTED += \
"syscfg\board.c" \
"syscfg\board.opt" \
"syscfg\device.c" \
"syscfg\c2000ware_libraries.opt" \
"syscfg\c2000ware_libraries.c" 

ASM_DEPS__QUOTED += \
"f280015x_codestartbranch.d" 

SYSCFG_SRCS__QUOTED += \
"../InterleavedPSU.syscfg" 

C_SRCS__QUOTED += \
"./syscfg/board.c" \
"./syscfg/device.c" \
"./syscfg/c2000ware_libraries.c" \
"C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/headers/source/f280015x_globalvariabledefs.c" \
"../main.c" 

ASM_SRCS__QUOTED += \
"C:/ti/C2000Ware_6_00_00_00/device_support/f280015x/common/source/f280015x_codestartbranch.asm" 


