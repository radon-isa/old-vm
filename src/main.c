#include <stdio.h>
#include "machine.h"

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    
    machine_t *m = vm_machine_create(256);

    vm_machine_write(m, 0x0, 0x1);
    vm_machine_write(m, 0x1, 0b10100001);
    vm_machine_write(m, 0x2, 0xca);
    vm_machine_write(m, 0x3, 0xfe);
    vm_machine_write(m, 0x4, 0x0);
    vm_machine_write(m, 0x5, 0b10111010);
    vm_machine_write(m, 0x6, 0x4);

    vm_machine_exec(m, 0x0);

    for (int i = 0; i < NUM_REGISTERS; i++) {
        printf("%d: %x\n", i, m->registers[i]);
    }

    vm_machine_destroy(m);
    return 0;
}