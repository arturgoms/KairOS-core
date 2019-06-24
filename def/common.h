// Board
#include "def/esp32.h"

// Common
#include <freertos/FreeRTOS.h>
#include <freertos/semphr.h>
#include <stdint.h>
#include <stdbool.h>

#define WATCH_ERR_FAIL 	1
#define WATCH_ERR_OK 	0

typedef uint8_t kairos_err_t;