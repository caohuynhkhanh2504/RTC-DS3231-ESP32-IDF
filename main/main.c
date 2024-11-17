#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <ds3231.h>
#include <string.h>

void ds3231_test(void *pvParameters)
{
    i2c_dev_t dev;
    memset(&dev, 0, sizeof(i2c_dev_t));

    ESP_ERROR_CHECK(ds3231_init_desc(&dev, 0, 21, 22));

    struct tm time = {
        .tm_year = 2024, // (2022 - 1900)
        .tm_mon  = 8,  // 0-based
        .tm_mday = 11,
        .tm_hour = 23,
        .tm_min  = 5,
        .tm_sec  = 0
    };
     ds3231_set_time(&dev, &time);  

    while (1)
    {
        vTaskDelay(pdMS_TO_TICKS(1000));

        if(ds3231_get_time(&dev, &time) == ESP_OK)
        {
            printf("%02d-%02d-%04d  %02d:%02d:%02d\n", time.tm_mday, time.tm_mon,
             time.tm_year, time.tm_hour, time.tm_min, time.tm_sec);
        }
        else
        {
            printf("Couldn't get time\n");
        }
    }
}

void app_main()
{

    xTaskCreate(ds3231_test, "ds3231_test", 2024 * 3, NULL, 5, NULL);
}