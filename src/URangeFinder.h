#ifndef URangeFinder_h
#define URangeFinder_h

#include "driver/gpio.h"
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#ifdef __cplusplus
extern "C"
{
#endif

    void init_urf(gpio_num_t Trigger_pin, gpio_num_t Echo_pin);
    int32_t lenkte_urf(gpio_num_t Trigger_pin, gpio_num_t Echo_pin);
    int32_t lenkte_urf_x_keer(gpio_num_t Trigger_pin, gpio_num_t Echo_pin, u_int8_t x_times);

#ifdef __cplusplus
}
#endif
#endif /* URangeFinder_h */