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

#ifdef __cplusplus
}
#endif
#endif /* URangeFinder_h */