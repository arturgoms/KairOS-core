#ifndef _HAL_TEMPERATURE_H_
#define _HAL_TEMPERATURE_H_

#include <stdint.h>


void init_temp(int SDA_PIN, int SCL_PIN);

float get_temp(void);


#endif