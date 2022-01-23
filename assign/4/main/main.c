// Create two task with priority 10 and 20. Each task prints its own custom message.
// 5. Swap the priority and observe the changes in the output. What is your conclusion on the
// sequence of printing the messages.

// higher priority will always execute and other will be in wait state  until or unless we provide delay then it will execute in
// that time

#include <stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>


void task1(void *pv)
 {
     while (1)
     {
        printf("sensor task \n"); 
        printf("stack remaining:%d",uxTaskPriorityGet(NULL)); // gives priority
     }
}

void task2(void *pv)
 {
 while (1)
     {
        printf("sensor task \n"); 
        printf("stack remaining:%d",uxTaskPriorityGet(NULL)); // gives priority
     }
}

int app_main()
{
  BaseType_t result;
  TaskHandle_t xHandle,xHandle2;

    result = xTaskCreate(task1,"Sensor",2048,NULL,10,&xHandle);
    result = xTaskCreate(task2,"buzzer",2048,NULL,20,&xHandle2);
    return 0;
}

// run 'idf.py -p (PORT) flash'