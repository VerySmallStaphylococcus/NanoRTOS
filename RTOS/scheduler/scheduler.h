#pragma once

//Task level classification enum
typedef enum {
    LV_1, // Must be the first to run (the most important task)
    LV_2, // Must run after Lv1 (the second most important task)
    LV_3  // Tasks to run after Lv1, Lv3 (Lowest priority task)
}LEVEL;