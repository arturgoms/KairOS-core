#include "system.h"

watch_err_t watch_system_init(void)
{
    init_peripherals();
    init_modules();
    printf("System initiated!\n");
    return 0;
}