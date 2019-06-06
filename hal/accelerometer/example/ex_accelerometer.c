#include "hal_accelerometer.h"
#include "drv/3rd/adxl345/drv_adxl345.h"

int SDA_GPIO;
int SCL_GPIO;


void init_accelerometer(int SDA_PIN, int SCL_PIN){
    SDA_GPIO = SDA_PIN;
    SCL_GPIO = SCL_PIN;
}

void get_accelerometer(int *result){
	adxl345_t dev;
    while (i2cdev_init() != ESP_OK)
    {
        printf("Could not init I2Cdev library\n");
        vTaskDelay(250 / portTICK_PERIOD_MS);
    }
    
    while (adxl345_init_desc(&dev, ADXL345_I2C_ADDRESS, 0, SDA_GPIO, SCL_GPIO) != ESP_OK)
    {
        printf("Could not init device descriptor\n");
        vTaskDelay(250 / portTICK_PERIOD_MS);
    }
	
	while (adxl345_init(&dev) != ESP_OK)
    {
        printf("Could not init accelerometer descriptor\n");
        vTaskDelay(250 / portTICK_PERIOD_MS);
    }
	uint8_t buff[A_TO_READ];
	int x,y,z;
	adxl345_readXYZ(&dev, buff);

	result[0] = (((int) buff[1]) << 8) | buff[0];
	result[1] = (((int) buff[3]) << 8) | buff[2];
	result[2] = (((int) buff[5]) << 8) | buff[4];
}

void app_main()
{
    init_accelerometer(15, 2);
    watch_system_init();

    int acc[3];
	while (1) {
		get_accelerometer(acc);
		ESP_LOGI("main","X=%d,Y=%d,Z=%d\n",(int8_t)acc[0],(int8_t)acc[1],(int8_t)acc[2]);
		vTaskDelay(1000 / portTICK_RATE_MS);
	}
}
