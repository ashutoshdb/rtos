#include <stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>
#include<freertos/timers.h>


TimerHandle_t motor_handle;

void MoterOff(TimerHandle_t xtimer) // timer handler
{
  printf("Timer is off");
}

int app_main()
{
  motor_handle = xTimerCreate("MotorOFF", pdMS_TO_TICKS(2000),pdTRUE, NULL,MoterOff); // 1 name 2 time in ticks 3 pd true for repeating and flase to no repeating
    // 4 timer id 5 function
    xTimerStart(motor_handle,0); // 2nd id delay after what time it start exec

    //  BaseType_t xTimerStart( TimerHandle_t xTimer,
    //                         TickType_t xBlockTime );

while(1){
  vTaskDelay(1000/portTICK_PERIOD_MS);
}
      return 0;
}

// run 'idf.py -p (PORT) flash'