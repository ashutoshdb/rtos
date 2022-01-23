// Find the APIs in your RTOS that provides timestamp and use it to print the periodic task.
// Observe the jitter in the timestamp vs the periodicity. Enhance the code to 10 periodic tasks
// with different periodicity. Futher observe the jitter in each of the task.


#include <stdio.h>

int app_main()
{
    printf("Hello C-DAC\n");
    return 0;
}

// run 'idf.py -p (PORT) flash'