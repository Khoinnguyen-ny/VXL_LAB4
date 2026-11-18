/*
 * scheduler.h
 *
 *  Created on: Nov 9, 2026
 *      Author: Admin
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>
#include "main.h"

#define SCH_MAX_TASKS   10
#define NO_TASK_ID      0

typedef struct {
    void (*pTask)(void);
    uint32_t Delay;      // Số tick còn lại trước khi thực thi
    uint32_t Period;     // Chu kỳ lặp lại (ticks), = 0 nếu là one-shot
    uint32_t RunMe;      // Cờ báo tác vụ đến lượt chạy
    uint32_t TaskID;     // ID định danh tác vụ
} sTask;

// Khai báo các hàm giao tiếp chuẩn theo yêu cầu bài lab
void SCH_Init(void);
void SCH_Update(void);
void SCH_Dispatch_Tasks(void);
uint32_t SCH_Add_Task(void (*pFunction)(void), uint32_t DELAY, uint32_t PERIOD);
uint8_t SCH_Delete_Task(uint32_t taskID);

#endif /* INC_SCHEDULER_H_ */
