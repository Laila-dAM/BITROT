#include <stdio.h>
#include "../kernel/include/scheduler.h"

static int counter_a = 0;
static int counter_b = 0;
static int counter_c = 0;

void task_a()
{
    counter_a++;
    scheduler_yield();
}

void task_b()
{
    counter_b++;
    scheduler_yield();
}

void task_c()
{
    counter_c++;
    scheduler_yield();
}

int main()
{
    scheduler_init();

    scheduler_add(task_a);
    scheduler_add(task_b);
    scheduler_add(task_c);

    for (int i = 0; i < 100; i++)
    {
        task_a();
        task_b();
        task_c();
    }

    if (counter_a == 100 && counter_b == 100 && counter_c == 100)
    {
        printf("Scheduler tests passed\n");
        return 0;
    }

    printf("Scheduler tests failed\n");
    return 1;
}
