#include "hal/modules.h"

watch_err_t init_modules(){
    init_accelerometer(I2C_SDA, I2C_SCL);
    init_temp(I2C_SDA, I2C_SCL);
    return 0;
}