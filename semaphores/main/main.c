#include <stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>
#include<freertos/semphr.h>

SemaphoreHandle_t sem;
  BaseType_t result;
  TaskHandle_t xHandle,xHandle2;

void sensor_task(void *pv)
 {
   int sensor_data =0;
   while(1){

  sensor_data++;
  printf("sensor task:%d\n",sensor_data); 
  vTaskDelay(1000/portTICK_PERIOD_MS);

    if(sensor_data==10){
      vTaskResume(xHandle2); // if u want ro resume another process pass handle of that function 
      //  xSemaphoreGive(sem);
    } 
   }
}

void processing_task(void *pv)
 {
   int recieved_data=0;
//   xSemaphoreTake(sem,portMAX_DELAY);
while(1){
  vTaskSuspend(NULL);   // we need to pass task handle and if u r n the task  u can pass null
   printf("data is:%d\n",recieved_data); 
   vTaskDelay(1000/portTICK_PERIOD_MS);
} }

int app_main()
{

    //sem =xSemaphoreCreateBinary(); 
    result = xTaskCreate(sensor_task,"Sensor",2048,NULL,5,&xHandle);   
    result = xTaskCreate(processing_task,"processing_task",2048,NULL,6,&xHandle2);
   // xSemaphoreTake(sem,portMAX_DELAY);

      return 0;
}

// run 'idf.py -p (PORT) flash'