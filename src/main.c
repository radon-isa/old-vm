#include <stdio.h>
#include "machine.h"

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    
    machine_t *m = vm_machine_create(256);
    vm_machine_destroy(m);
    return 0;
}