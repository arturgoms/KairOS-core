
#ifndef _HAL_ACCELEROMETER_H_
#define _HAL_ACCELEROMETER_H_

#include <stdint.h>
#include "drv/3rd/adxl345/drv_adxl345.h"

#define A_TO_READ (6)

kairos_err_t init_accelerometer(int SDA_PIN, int SCL_PIN);

void get_accelerometer(int *result);

#endif // _HAL_ACCELEROMETER_H_