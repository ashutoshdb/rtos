#include <stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>
#include<driver/gpio.h>

#define ALARM_TASK 15


void sensor_task(void *pv)
 {
    while (1)
  {
printf("sensor task \n"); 
printf("stack remaining:%d",uxTaskGetStackHighWaterMark(NULL)); // remaining stack
printf("stack remaining:%d",uxTaskPriorityGet(NULL)); // gives priority
printf("stack remaining:%d",xTaskGetAffinity(NULL)); // cpu id
vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}

void buzzer_task(void *pv)
 {
  // esp_rom_gpio_pad_select_gpio(ALARM_TASK); // select gpio pin
  // gpio_set_direction(ALARM_TASK, GPIO_MODE_OUTPUT);
  while (1)
  {
      printf("stack remaining:%d",uxTaskGetStackHighWaterMark(NULL)); // remaining stack
printf("stack remaining:%d",uxTaskPriorityGet(NULL)); // gives priority
printf("stack remaining:%d",xTaskGetAffinity(NULL)); // cpu id
  
    // gpio_set_level(ALARM_TASK, 0); // swtting gpio to low 
    // vTaskDelay(1000/portTICK_PERIOD_MS);
    // gpio_set_level(ALARM_TASK, 1  ); // high
    vTaskDelay(1000/portTICK_PERIOD_MS);
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
    result = xTaskCreate(buzzer_task,"buzzer",2048,NULL,4,&xHandle2);
    if(result==pdPASS){
      printf("TAsk created");
    }
      return 0;
}

// run 'idf.py -p (PORT) flash'