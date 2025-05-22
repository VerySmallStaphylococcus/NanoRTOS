#pragma once

//the function pointer of the beginning :)
typedef int (*func)(void *p); 

//Task level classification enum
typedef enum {
    LV_1, // Must be the first to run (the most important task)
    LV_2, // Must run after Lv1 (the second most important task)
    LV_3  // Tasks to run after Lv1, Lv3 (Lowest priority task)
}LEVEL;

//Task Information
typedef struct
{
    //function
    func function; // call back function
    void *function_arg; // argument

    //level & task end time
    LEVEL lv;      //task level
    int end_time;  //task end time

}task_info;

//the task function (It's a function of the beginning) :)
int lR_task(task_info info);