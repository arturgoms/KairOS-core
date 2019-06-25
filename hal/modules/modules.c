#include "hal/modules/modules.h"

kairos_err_t init_modules(void){
    kairos_err_t passed = KAIROS_ERR_FAIL;
    passed |= init_accelerometer(I2C_SDA, I2C_SCL);
    passed |= init_temp(I2C_SDA, I2C_SCL);
    return passed;
}