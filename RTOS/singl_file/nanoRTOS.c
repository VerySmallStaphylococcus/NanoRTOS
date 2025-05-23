#include "./nanoRTOS.h"

//Raspberry Pi Pico 
volatile uint32_t system_time_ms = 0;

void SysTick_Handler(void) {
    system_time_ms++;
}

void timer_init(void) {
    //setup RP2040 SysTick (125MHz)
    *((volatile unsigned int*)0xE000E014) = 125000 - 1; // Reload
    *((volatile unsigned int*)0xE000E018) = 0;           // Clear current
    *((volatile unsigned int*)0xE000E010) = 0x07;        // Enable, interrupt, processor clock
}

uint32_t get_system_time_ms(void) {
    return system_time_ms;
}

//tasks loop
int Tasks_loop(task_info tasks[numof_tasks]) {

    //init the timer
    timer_init();

    //checking levels and list up the tasks
    task_info task_list[numof_tasks]; //tasks list
    //Loop as many tasks as possible
    //this loop is checking the number of each level tasks
    int lv1_count = 0, lv2_count = 0, lv3_count = 0; 
    for (NUMOF_TASKS i = 0; i < numof_tasks; i++) {
        switch (tasks[i].lv) {
            case LV_1: lv1_count++; break;
            case LV_2: lv2_count++; break;
            case LV_3: lv3_count++; break;
            default: return 1;
        }
    }
    //list up the tasks
    int lv1_index = 0, lv2_index = lv1_count, lv3_index = lv1_count + lv2_count; //indexs
    //list up
    for (NUMOF_TASKS i = 0; i < numof_tasks; i++) {
        switch (tasks[i].lv) {
            case LV_1:
                task_list[lv1_index++] = tasks[i];
                break;
            case LV_2:
                task_list[lv2_index++] = tasks[i];
                break;
            case LV_3:
                task_list[lv3_index++] = tasks[i];
                break;
            default:
                return 1;
        }
}

    //tasks loop
    int tasks_p = 0; //tasks pointer
    while (1)   {
        int err = task_list[tasks_p].function(task_list[tasks_p].function_arg);
        
        //error checking
        if (err == 0)   continue; //end very good
        if (err == 1) return 1; //error
        
        tasks_p++;
        if (tasks_p >= numof_tasks) {
            tasks_p = 0;
        }
    }
    
}

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