#include "../include/scheduler.h"

static task_t tasks[MAX_TASKS];
static int task_count = 0;
static int current_task = -1;

void scheduler_init()
{
    for (int i = 0; i < MAX_TASKS; i++)
    {
        tasks[i].entry = 0;
        tasks[i].active = 0;
    }

    task_count = 0;
    current_task = -1;
}

int scheduler_add(task_entry_t entry)
{
    if (task_count >= MAX_TASKS)
        return -1;

    tasks[task_count].entry = entry;
    tasks[task_count].active = 1;
    task_count++;

    return 0;
}

void scheduler_yield()
{
    if (task_count == 0)
        return;

    current_task++;
    if (current_task >= task_count)
        current_task = 0;
}

void scheduler_run()
{
    if (task_count == 0)
        return;

    current_task = 0;

    while (1)
    {
        if (tasks[current_task].active && tasks[current_task].entry)
        {
            tasks[current_task].entry();
        }

        scheduler_yield();
    }
}
