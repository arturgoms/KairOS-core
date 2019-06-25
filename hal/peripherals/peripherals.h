#ifndef _LIB_PERIPHERALS_H_
#define _LIB_PERIPHERALS_H_

#include "drv/3rd/adxl345/drv_adxl345.h"
#include "drv/3rd/bmp280/drv_bmp280.h"
#include "drv/wifi/drv_wifi.h"
#include "drv/audio/drv_audio.h"
#include "drv/battery/drv_battery.h"
#include "drv/bluetooth/drv_bluetooth.h"
#include "drv/display/drv_display.h"
#include "drv/input/drv_input.h"
#include "drv/power/drv_power.h"
#include "drv/protocols/i2c/drv_i2c.h"
#include "drv/storage/drv_storage.h"
#include "drv/usb/drv_usb.h"
#include "drv/wifi/drv_wifi.h"
#include "def/common.h"

extern kairos_err_t init_peripherals(void);

#endif // _LIB_PERIPHERALS_H_