#ifdef __INTELLISENSE__

//#include <stdint.h>  // Let VSCode use the standard types

// Define TI intrinsics and macros for IntelliSense only
#define __byte_peripheral_32(addr) (*((volatile unsigned long *)(addr)))
#define HWREG_BP(x) (*((volatile unsigned long *)(x)))
#define HWREG(x)    (*((volatile unsigned long *)(x)))
#define HWREGH(x)   (*((volatile unsigned int  *)(x)))

// You can add other TI-specific intrinsics or macros here as needed
// volatile unsigned int IFR;
// volatile unsigned int IER;


// #define __interrupt       /* Used for TI ISR declarations */
// #define __cregister       /* Used for CPU register declarations */

/* No-op the C28x inline asm style macros for IntelliSense */
// #define EALLOW  do{}while(0)
// #define EDIS    do{}while(0)
// #define DINT    do{}while(0)
// #define EINT    do{}while(0)
// #define ERTM    do{}while(0)
// #define DRTM    do{}while(0)

// intrinsics
static inline float __fsat(float v, float hi, float lo)       { return v; }
static inline float __einvf32(float x)                        { return 1.0f / x; }
static inline int   __f32toi16r(float x)                      { return (int)(x + 0.5f); }
static inline int   __f32toui16r(float x)                     { return (unsigned int)(x + 0.5f); }
static inline float __fmax(float a, float b)                  { return a > b ? a : b; }
static inline float __fmin(float a, float b)                  { return a < b ? a : b; }

#endif


