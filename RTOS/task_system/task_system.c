#include "./task_system.h"

//the task function (It's a function of the beginning) :)
int lR_task(task_info info) {
    //Task loop
    while (1)
    {
        //run function
        int err = info.function(info.function_arg);
        //error check
        if (err == 1)   {
            return 1; //return error
        }
    }
}