#include <stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>
#include<freertos/event_groups.h>


EventGroupHandle_t  sensor_event;
const uint32_t temp_event_bit =(1 << 0);
const uint32_t pres_event_bit = (1 << 1);
const uint32_t allbit = (temp_event_bit | pres_event_bit);

void temp_task(void *pv)
 {
   while (1)
   {
    printf("temp task \n");
    xEventGroupSetBits(sensor_event,temp_event_bit);
       vTaskDelay(1000/portTICK_PERIOD_MS);
   }
   
}
void pressure_task(void *pv)
 {
   while (1)
   {
    printf("press task \n");
    xEventGroupSetBits(sensor_event,pres_event_bit);
       vTaskDelay(2000/portTICK_PERIOD_MS);
   }


 
}
void calibration_task(void *pv)
 {
   uint32_t result;
    printf("cal task \n");
while(1){
     result =  xEventGroupWaitBits(sensor_event,allbit,pdTRUE,pdTRUE, pdMS_TO_TICKS(5000));
                      //  const EventGroupHandle_t xEventGroup,
                      //  const EventBits_t uxBitsToWaitFor,
                      //  const BaseType_t xClearOnExit,
                      //  const BaseType_t xWaitForAllBits,
                      //  TickType_t xTicksToWait

}
vTaskDelete(NULL);
   
}

int app_main()
{
    BaseType_t result;
    TaskHandle_t xHandle0,xHandle1,xHandle2;

    sensor_event=  xEventGroupCreate();  // created a event

    result = xTaskCreate(temp_task,"temp",2048,NULL,5,&xHandle0); // task created
    result = xTaskCreate(pressure_task,"press",2048,NULL,5,&xHandle1); 
    result = xTaskCreate(calibration_task,"cal",2048,NULL,5,&xHandle2); 
      return 0;
}

// run 'idf.py -p (PORT) flash'