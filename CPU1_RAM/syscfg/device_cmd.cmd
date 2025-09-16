
//
// Active linker CMD configuration selected by 
// the CMD Tool global settings
//
#define CMD0
#ifdef CMD0

MEMORY
{

    RAMM0_BEGIN               : origin = 0x000000, length = 0x000002
    RAMM0                     : origin = 0x000128, length = 0x0002D8
    RAMM1                     : origin = 0x000400, length = 0x0003F8
    RAMLS_ALL                 : origin = 0x008000, length = 0x003FF8
    FLASH_BANK0_SEC_0_7       : origin = 0x080000, length = 0x002000
    FLASH_BANK0_SEC_8_15      : origin = 0x082000, length = 0x002000
    FLASH_BANK0_SEC_16_23     : origin = 0x084000, length = 0x002000
    FLASH_BANK0_SEC_24_31     : origin = 0x086000, length = 0x002000
    FLASH_BANK0_SEC_32_29     : origin = 0x088000, length = 0x002000
    FLASH_BANK0_SEC_40_47     : origin = 0x08A000, length = 0x002000
    FLASH_BANK0_SEC_48_55     : origin = 0x08C000, length = 0x002000
    FLASH_BANK0_SEC_56_63     : origin = 0x08E000, length = 0x002000
    FLASH_BANK0_SEC_64_71     : origin = 0x090000, length = 0x002000
    FLASH_BANK0_SEC_72_79     : origin = 0x092000, length = 0x002000
    FLASH_BANK0_SEC_80_87     : origin = 0x094000, length = 0x002000
    FLASH_BANK0_SEC_88_95     : origin = 0x096000, length = 0x002000
    FLASH_BANK0_SEC_96_103    : origin = 0x098000, length = 0x002000
    FLASH_BANK0_SEC_104_111   : origin = 0x09A000, length = 0x002000
    FLASH_BANK0_SEC_112_119   : origin = 0x09C000, length = 0x002000
    FLASH_BANK0_SEC_120_127   : origin = 0x09E000, length = 0x001FF0
    RESET                     : origin = 0x3FFFC0, length = 0x000002
}


SECTIONS
{
    //
    // C28x Sections
    //
    .reset               : >  RESET, TYPE = DSECT /* not used, */
    codestart            : >  0x000000
    .text                : >  RAMLS_ALL
    .TI.ramfunc          : >  RAMM0
    .cinit               : >  RAMM0
    .stack               : >  RAMM1
    .init_array          : >  RAMM0
    .bss                 : >  RAMLS_ALL
    .const               : >  RAMLS_ALL
    .data                : >  RAMLS_ALL
    .switch              : >  RAMM0
    .sysmem              : >  RAMLS_ALL

    //
    // User Sections
    //
    DCL_funcs { *(dclfuncs) }    >  RAMLS_ALL
    CODESTART { *(codestart) }    >  RAMM0

}

#endif

/*
//===========================================================================
// End of file.
//===========================================================================
*/
