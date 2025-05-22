#pragma once

//the function pointer of the beginning :)
typedef int (*func)(void *p); 

//Task Information
typedef struct
{
    //function
    func function; // call back function
    void *function_arg; // argument

    int end_time;  //task end time

}task_info;

//the task function (It's a function of the beginning) :)
int lR_task(task_info info);