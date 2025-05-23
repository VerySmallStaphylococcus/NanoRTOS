#include "../task_system/task_system.h"
#include "./scheduler.h"
#include "../timer/timer.h"

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
}