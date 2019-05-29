#ifndef _LIB_SYSTEM_H_
#define _LIB_SYSTEM_H_ 

#include <stdint.h>
#include <freertos/FreeRTOS.h>

#define WATCH_ERR_FAIL 	1
#define WATCH_ERR_OK 		0

typedef uint8_t watch_err_t;
watch_err_t watch_system_init(void);

#endif