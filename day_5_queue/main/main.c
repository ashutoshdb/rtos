#include <stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>
#include<freertos/queue.h>
#include<driver/gpio.h>

#define ALARM_TASK 15

QueueHandle_t sensor_que;


void sensor_task(void *pv)
 {
   int sensor_data =0;
   while(1){
     sensor_data++;
  printf("sensor task:%d\n",sensor_data); 
  xQueueSend(sensor_que,&sensor_data, portMAX_DELAY); // 1 que 2 variable which data to be shared 3 max amount of time to wait portMAX_DELAY
  vTaskDelay(1000/portTICK_PERIOD_MS);
   }
}

void processing_task(void *pv)
 {
   while(1){
   int recieved_data;
  xQueueReceive(sensor_que,&recieved_data,portMAX_DELAY);
   printf("data is:%d\n",recieved_data); 
   vTaskDelay(5000/portTICK_PERIOD_MS);
   }
} 

int app_main()
{

  BaseType_t result;
  TaskHandle_t xHandle,xHandle2;

    sensor_que = xQueueCreate(10,sizeof(int)); // lenghtof the queue  2nd size of each item of queue
    printf("Hello pthread\n");  
    result = xTaskCreate(sensor_task,"Sensor",2048,NULL,5,&xHandle);   
    result = xTaskCreate(processing_task,"processing_task",2048,NULL,4,&xHandle2);

      return 0;
}

// run 'idf.py -p (PORT) flash'