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

12 incomplte for now
13. Does your RTOS provide APIs to collect task statistics. If yes, list the statistics parameters
that are collected and write a program to display the runtime task statistics?
14. Find the tick frequency configuration for your RTOS.
15. Create a task to suspend itself after 1200 ms and resume it from another task
16. Write a RTOS application to demonstrate the use of changing priority
17. If you RTOS supports idle task hooking, write a program to demonstrate it
18. Write a RTOS application to demonstrate the use of task to task communication using
Queue management APIs. Also demonstrate blocking on a queue.
19. Write a RTOS application to demonstrate the effects of task priorities when sending to and
receiving from a queue.
20. Write a RTOS application to demonstrate deferred interrupt processing using binary semaphores
21. Write a RTOS application to demonstrate counting semaphores to synchronize a task
22. Write a RTOS application to demonstrate the usage of queues within an interrupt service
routine
23. Write a RTOS application to manage resources using mutual exclusion
24. Write a RTOS application to demonstrate a priority inversion problem. If your RTOS sup-
ports priority inheritance or priority ceiling, use it to solve the priority inversion problem.
25. Write a RTOS application to create a software timer that invokes a callback function every
5 seconds.