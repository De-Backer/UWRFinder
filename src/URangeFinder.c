#include "esp_timer.h"
#include "URangeFinder.h"

#define trigger 22
#define echo 23

/// @brief initialize Ultrasonic Range Finder
/// @param Trigger_pin pin numer van de esp die naar de Trigger pin gaat
/// @param Echo_pin pin numer van de esp die naar de Echo pin gaat
void init_urf(gpio_num_t Trigger_pin, gpio_num_t Echo_pin)
{
    gpio_set_direction(Trigger_pin, GPIO_MODE_OUTPUT);
    gpio_set_direction(Echo_pin, GPIO_MODE_INPUT);
    gpio_set_pull_mode(Echo_pin, GPIO_PULLDOWN_ONLY);
}

/// @brief vraagt de afstand van de Ultrasonic Range Finder
/// @param Trigger_pin pin numer van de esp die naar de Trigger pin gaat
/// @param Echo_pin pin numer van de esp die naar de Echo pin gaat
/// @return de afstand in µm
int32_t lenkte_urf(gpio_num_t Trigger_pin, gpio_num_t Echo_pin)
{
    // set trigger signal 10µs high
    gpio_set_level(Trigger_pin, 1);
    vTaskDelay(1 / portTICK_RATE_MS);
    gpio_set_level(Trigger_pin, 0);

    // Echo Pulse width
    int64_t start_tijd = 0;
    for (int32_t i = 0; i < 0xfffff; ++i)
    {
        if (gpio_get_level(Echo_pin) == 1)
        {
            start_tijd = esp_timer_get_time();
            i = 0xfffff; // exit de loop
        }
    }
    int64_t stop_tijd = 0;
    for (int32_t i = 0; i < 0xfffff; ++i)
    {
        if (gpio_get_level(Echo_pin) == 0)
        {
            stop_tijd = esp_timer_get_time();
            i = 0xfffff; // exit de loop
        }
    }
    // 60ms == End of measurement
    int64_t delta = stop_tijd - start_tijd;
    // Test distance = (high time * speed of sound (340M / s)) / 2;
    // 340M/s => 340000mm/s =>/2 => 170000mm/s => 170mm/ms => 170µm/µs
    // opm: de temperatuur doet de geluidssnelheid stijgen!
    // 20*vierkantswortel(273+temperatuur)=geluidssnelheid
    // 330m/s 0°C -- 350m/s 30°C

    if (delta > 20000000)
    {
        return -1; // > 3,5km dat zal wel fout zijn.
    }
    // ja we gaan van een int64_t naar een int32_t
    int32_t lenkte_in_um = delta * 175;
    // printf("lenkte %" PRId64 "µm\n", lenkte_in_um);
    return lenkte_in_um;
}
