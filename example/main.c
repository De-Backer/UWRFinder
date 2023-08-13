
#include <stdint.h>
#include <inttypes.h>

#include "URangeFinder.h"

#define trigger 22
#define echo 23

void app_main()
{
    init_urf(trigger, echo);
    for (;;)
    {
        printf(">lenkte:%" PRId32 "µm\n", lenkte_urf(trigger, echo));
        vTaskDelay(100 / portTICK_RATE_MS);
        printf(">lenkte_av:%" PRId32 "µm\n", lenkte_urf_x_keer(trigger, echo, 18));
        vTaskDelay(100 / portTICK_RATE_MS);
    }
}