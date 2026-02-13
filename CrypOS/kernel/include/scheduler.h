#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdint.h>

#define MAX_TASKS 16

typedef void (*task_entry_t)(void);

typedef struct {
    task_entry_t entry;
    uint8_t active;
} task_t;

void scheduler_init();
int scheduler_add(task_entry_t entry);
void scheduler_run();
void scheduler_yield();

#endif
