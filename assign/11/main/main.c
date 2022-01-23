// 11. What is the API for deleting a task? Write a program demonstrate this capability.

#include <stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>

void buzzer_task(void *pv)
 {
    printf("buzzer task \n");
    vTaskDelete(NULL);
}

int app_main()
{
    BaseType_t result;
    TaskHandle_t xHandle;
    printf("Hello \n");  
    result = xTaskCreate(sensor_task,"Sensor",2048,NULL,5,&xHandle);
    return 0;
}

// run 'idf.py -p (PORT) flash'