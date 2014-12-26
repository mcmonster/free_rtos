#define GCC_ARM_CM4F 1
#define GCC_POSIX 2

#if FREE_RTOS_PORT == GCC_ARM_CM4F
    #include "../portable/GCC/ARM_CM4F/portmacro.h"
#elif FREE_RTOS_PORT == GCC_POSIX
    #include "../portable/GCC/Posix/portmacro.h"
#else
    #error "Please define FREE_RTOS_PORT to valid value!"
#endif
