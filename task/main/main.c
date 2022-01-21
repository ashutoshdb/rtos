#include <stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>


void sensor_task(void *pv)
 {
   while (1)
   {
    printf("sensor task \n");
   }
   
}

void buzzer_task(void *pv)
 {
   while (1)
   {
    printf("buzzer task \n");
   }
   

}

int app_main()
{
BaseType_t result;
  TaskHandle_t xHandle,xHandle2;
    printf("Hello pthread\n");  
    result = xTaskCreate(sensor_task,"Sensor",2048,NULL,5,&xHandle);
    if(result==pdPASS){
      printf("TAsk created");
    } 
    result = xTaskCreate(buzzer_task,"buzzer",2048,NULL,4,&xHandle2); // task created
    if(result==pdPASS){
      printf("TAsk created");
    }
      return 0;
}

// run 'idf.py -p (PORT) flash'