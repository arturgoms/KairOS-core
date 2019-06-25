// Board
#include "def/esp32.h"

// Common
#include <freertos/FreeRTOS.h>
#include <freertos/semphr.h>
#include <stdint.h>
#include <stdbool.h>
#include "esp_pm.h"
#include "esp_wifi.h"
#include "esp_log.h"
#include "esp_event.h"
#include "nvs_flash.h"

#define KAIROS_ERR_FAIL 1
#define KAIROS_ERR_OK 	0

#define core_v 0.2.0

typedef uint8_t kairos_err_t;