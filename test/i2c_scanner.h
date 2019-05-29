#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <stdio.h>
#include <driver/i2c.h>

#define SDA_PIN 15
#define SCL_PIN 2

void task_i2cscanner(void *ignore);

