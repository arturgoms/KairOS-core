#ifndef _LIB_MODULES_H_
#define _LIB_MODULES_H_

#include "hal/accelerometer/hal_accelerometer.h"
#include "hal/temperature/hal_temperature.h"
#include "hal/audio/hal_temperature.h"
#include "hal/battery/hal_battery.h"
#include "hal/bluetooth/hal_bluetooth.h"
#include "hal/display/hal_display.h"
#include "hal/humidity/hal_humidity.h"
#include "hal/input/hal_input.h"
#include "hal/power/hal_power.h"
#include "hal/pressure/hal_pressure.h"
#include "hal/storage/hal_storage.h"
#include "hal/usb/hal_usb.h"
#include "hal/wifi/hal_wifi.h"

watch_err_t init_modules(void);

#endif // _LIB_MODULES_H_