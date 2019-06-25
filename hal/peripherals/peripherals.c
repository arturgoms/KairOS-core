#include "hal/peripherals/peripherals.h"

kairos_err_t init_peripherals(void){
    kairos_err_t passed = KAIROS_ERR_FAIL;
    passed |= audio_init();
    passed |= battery_init();
    passed |= bluetooth_init();
    passed |= display_init();
    passed |= input_init();
    passed |= cpu_init();
    passed |= power_init();
    passed |= i2cdev_init();
    passed |= storage_init();
    passed |= usb_init();
    passed |= wifi_init();
    return passed;
}