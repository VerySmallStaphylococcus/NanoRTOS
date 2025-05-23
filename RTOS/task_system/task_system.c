#include "./task_system.h"
#include "../timer/timer.h"

//the task function (It's a function of the beginning) :)
int lR_task(task_info info) {
    
    //Task loop
    while (1)
    {
        //run function
        int err = info.function(info.function_arg);
        //error check
        if (err == 1) return 1; //return error

        //end check 
        if (err == 0) return 0; //end the task
        
        //if the time is over, End the task
        if ((int)(get_system_time_ms() - info.end_time) >= 0) return 1;

    }
}