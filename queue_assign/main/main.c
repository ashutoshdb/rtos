#include <stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>
#include<freertos/queue.h>
#include<driver/gpio.h>

#define ALARM_TASK 15

QueueHandle_t sensor_que;

  BaseType_t result;
  TaskHandle_t xHandle,xHandle2;



void sensor_task(void *pv)
 {
   int sensor_data =0;
   while(1){
     sensor_data++;
        if (sensor_data==11)
   {
      vTaskResume(xHandle2);
   }
  printf("sensor task:%d\n",sensor_data); 
  xQueueSend(sensor_que,&sensor_data, portMAX_DELAY); // 1 que 2 variable which data to be shared 3 max amount of time to wait portMAX_DELAY
  vTaskDelay(1000/portTICK_PERIOD_MS);
   }

   
}

void processing_task(void *pv)
 {
   int recieved_data;
    vTaskSuspend(NULL);
  xQueueReceive(sensor_que,&recieved_data,portMAX_DELAY);
   printf("data is:%d\n",recieved_data); 
   vTaskDelay(1000/portTICK_PERIOD_MS);
} 

int app_main()
{

    sensor_que = xQueueCreate(10,sizeof(int)); // lenghtof the queue  2nd size of each item of queue 
    result = xTaskCreate(sensor_task,"Sensor",2048,NULL,5,&xHandle);   
    result = xTaskCreate(processing_task,"processing_task",2048,NULL,4,&xHandle2);

      return 0;
}
