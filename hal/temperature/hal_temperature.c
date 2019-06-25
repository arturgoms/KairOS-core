#include "hal_temperature.h"

int SDA_GPIO;
int SCL_GPIO;
bmp280_t dev;
bool bme280p;

kairos_err_t  init_temp(int SDA_PIN, int SCL_PIN){
    SDA_GPIO = SDA_PIN;
    SCL_GPIO = SCL_PIN;
    bmp280_params_t params;
    bmp280_init_default_params(&params);
    

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
        printf("Could not init BMP280, err: %d\n", res);
        vTaskDelay(250 / portTICK_PERIOD_MS);
    }

    bme280p = dev.id == BME280_CHIP_ID;
    printf("BMP280: found %s\n", bme280p ? "BME280" : "BMP280");

    return KAIROS_ERR_OK;
}

float get_temp(void){
    float pressure, temperature, humidity;

    if (bmp280_read_float(&dev, &temperature, &pressure, &humidity) != ESP_OK)
    {
        printf("Temperature/pressure reading failed\n");
        return KAIROS_ERR_FAIL;
    }
    
    return temperature;
    
}

float get_humidity(void){
    float pressure, temperature, humidity;

    if (bmp280_read_float(&dev, &temperature, &pressure, &humidity) != ESP_OK)
    {
        printf("Temperature/pressure reading failed\n");
    }

    if (bmp280_read_float(&dev, &temperature, &pressure, &humidity) != ESP_OK)
    {
        printf("Temperature/pressure reading failed\n");
        return KAIROS_ERR_FAIL;
    }
    
    return humidity;
}

float get_pressure(void){
    float pressure, temperature, humidity;

    if (bmp280_read_float(&dev, &temperature, &pressure, &humidity) != ESP_OK)
    {
        printf("Temperature/pressure reading failed\n");
        return KAIROS_ERR_FAIL;
    }
    
    return pressure;
    
}