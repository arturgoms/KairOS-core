#include "lib/system.h"

kairos_err_t watch_system_init(void)
{
    kairos_err_t passed = KAIROS_ERR_FAIL;
    
    passed |= init_peripherals();
    passed |= init_modules();

    printf("System initiated!\n");

    return passed;
}