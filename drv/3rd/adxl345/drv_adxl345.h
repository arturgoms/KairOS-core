#ifndef __ADXL345_H__
#define __ADXL345_H__

#include <stdint.h>
#include <stdbool.h>
#include <esp_err.h>
#include "drv/protocols/i2c/drv_i2c.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ADXL345_I2C_ADDRESS     0x53        // Address

double gains[3];

typedef struct {

    i2c_dev_t  i2c_dev;
    uint8_t  id;

} adxl345_t;

void adxl345_read(adxl345_t *dev,int *xyz);
esp_err_t adxl345_init_desc(adxl345_t *dev, uint8_t addr, i2c_port_t port, gpio_num_t sda_gpio, gpio_num_t scl_gpio);
esp_err_t adxl345_init(adxl345_t *dev);
esp_err_t adxl345_readXYZ(adxl345_t *dev, double *xyz);

#ifdef __cplusplus
}
#endif

#endif  // __ADXL345_H__
