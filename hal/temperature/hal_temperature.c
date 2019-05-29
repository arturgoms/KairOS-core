#include "hal_temperature.h"
#include "drv/3rd/bmp280/drv_bmp280.h"

int SDA_GPIO;
int SCL_GPIO;

void  init_temp(int SDA_PIN, int SCL_PIN){
    SDA_GPIO = SDA_PIN;
    SCL_GPIO = SCL_PIN;
}

float get_temp(void){
    bmp280_params_t params;
    bmp280_init_default_params(&params);
    bmp280_t dev;

    esp_err_t res;

    while (i2cdev_init() != ESP_OK)
    {
        printf("Could not init I2Cdev library\n");
        vTaskDelay(250 / portTICK_PERIOD_MS);
    }
    
    while (bmp280_init_desc(&dev, BMP280_I2C_ADDRESS_0, 0, SDA_GPIO, SCL_GPIO) != ESP_OK)
    {
        printf("Could not init device descriptor\n");
        vTaskDelay(250 / portTICK_PERIOD_MS);
    }

    while ((res = bmp280_init(&dev, &params)) != ESP_OK)
    {
        printf("Could not init BMP281, err: %d\n", res);
        vTaskDelay(250 / portTICK_PERIOD_MS);
    }

    bool bme280p = dev.id == BME280_CHIP_ID;
    printf("BMP280: found %s\n", bme280p ? "BME280" : "BMP280");

    float temperature, pressure, humidity;

    if (bmp280_read_float(&dev, &temperature, &pressure, &humidity) != ESP_OK)
    {
        printf("Temperature/pressure reading failed\n");
        return 1;
    }
    else
    {
        return temperature;
    }
}