#include "drv_cpu.h"

kairos_err_t cpu_init(void)
{
    esp_pm_config_esp32_t pm_config = {
        .max_freq_mhz = 2,
        .min_freq_mhz = 2,
        .light_sleep_enable = true
    };

    esp_pm_configure(&pm_config);
    printf("CPU configured! %dMhz Light Mode: Enabled\n", rtc_clk_cpu_freq_get());
    return KAIROS_ERR_OK;
}
