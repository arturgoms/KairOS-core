#ifndef _HAL_TEMPERATURE_H_
#define _HAL_TEMPERATURE_H_

#include <stdint.h>
#include "drv/3rd/bmp280/drv_bmp280.h"

kairos_err_t init_temp(int SDA_PIN, int SCL_PIN);

float get_temp(void);


#endif