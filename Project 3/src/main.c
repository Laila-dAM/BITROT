#include <stdio.h>
#include <stdlib.h>
#include "inventory_system.h"

int system_start(void)
{
    printf("%s\n", APP_NAME);
    printf("Version %s\n", APP_VERSION);
    return 0;
}

int system_shutdown(void)
{
    return 0;
}

int main(void)
{
    system_start();
    system_shutdown();
    return EXIT_SUCCESS;
}
