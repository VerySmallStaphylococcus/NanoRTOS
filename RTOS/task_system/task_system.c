#include "./task_system.h"

//the task function (It's a function of the beginning) :)
int lR_task(task_info info) {
    switch (info.lv)    {
    
    //run level 1 task
    case LV_1:
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
        
        
        break;

    //run level 2 task
    case LV_2:
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

        break;
    
    //run level 3 task
    default:
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

        break;
    }
}