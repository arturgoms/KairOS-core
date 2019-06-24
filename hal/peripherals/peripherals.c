#include "hal/peripherals.h"

watch_err_t init_peripherals(){
    audio_init();
    battery_init();
    bluetooth_init();
    display_init();
    input_init();
    power_init();
    i2c_init();
    storage_init();
    usb_init();
    wifi_init();
    return 0;
}