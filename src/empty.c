/**
 * Copyright (c) 2022 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"

#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "pico/cyw43_arch.h"

int count = 0;
bool on = false;
#define MAIN_TASK_STACK_SIZE configMINIMAL_STACK_SIZE
#define MAIN_TASK_PRIORITY      ( tskIDLE_PRIORITY + 1UL )
#define BUSY_TASK_PRIORITY     ( tskIDLE_PRIORITY + 2UL )
#define BUSY_TASK_STACK_SIZE configMINIMAL_STACK_SIZE

void busy_task(__unused void *params) {
    for (;;) {
        continue;
    }
}

int main( void )
{
    stdio_init_all();
    const char *rtos_name;
    rtos_name = "FreeRTOS";
    TaskHandle_t task;
    
    hard_assert(cyw43_arch_init() == PICO_OK);
    
    xTaskCreate(busy_task, "BusyThread",
                MAIN_TASK_STACK_SIZE, NULL, MAIN_TASK_PRIORITY, &task);
    vTaskStartScheduler();

    return 0;
}