# 1.Find the range of priority that can be assigned to a task for your RTOS. 
- If the port in use implements a port optimised task selection mechanism that uses a 'count leading zeros' type instruction (for task selection in a single instruction) and configUSE_PORT_OPTIMISED_TASK_SELECTION is set to 1 in FreeRTOSConfig.h, then configMAX_PRIORITIES cannot be higher than 32. In all other cases configMAX_PRIORITIES can take any value within reason - but for reasons of RAM usage efficiency should be kept to the minimum value actually necessary.

# 5. Swap the priority and observe the changes in the output. What is your conclusion on the sequence of printing the messages.
- higher priority will always execute and other will be in wait state  until or unless we provide delay then it will execute in that time

# 6. What are the maximum number of tasks that can be created on the RTOS you are using? Is it limited by the RTOS design or underlying hardware resources or both.
- There is nothing in FreeRTOS that limits the number of created tasks except the available FreeRTOS heap space

# 7. What is the scheduling algorithm used by your RTOS?
- priority based preemptive scheduling and sometime round -robin for same priority

# 8. List the customization options for creating a task for the RTOS you are using. eg. priority etc
- xTaskCreate(buzzer_task,"buzzer",2048,NULL,4,&xHandle2) 
    - 1 it passes a function in which task is exectution is defined
    - 2 Name of that particular task 
    - 3 size of stack 
    - 4 arguements
    - 5 handle function for that task

# 9. Find the fields that are maintained in the Task Control Block / Process Control Block of the RTOS you are using.
- Pointer,Process state,Process number,Program counter,Register,Memory limits,Open files list  

# 10 Draw a process or task state diagram for the RTOS you are using.
- DORMANT -> ready state ->running state -> wait state -> ISR
# Find the tick frequency configuration for your RTOS.
- 100Hz
