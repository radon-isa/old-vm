#include <stdio.h>
#include "machine.h"

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    
    machine_t *m = vm_machine_create(256);

    vm_machine_write(m, 0x0, 0x1);
    vm_machine_write(m, 0x1, 0b10100010);
    vm_machine_write(m, 0x2, 0xca);
    vm_machine_write(m, 0x3, 0xfe);
    vm_machine_write(m, 0x4, 0x0);
    vm_machine_write(m, 0x5, 0b10111010);
    vm_machine_write(m, 0x6, 0x2);
    vm_machine_write(m, 0x7, 0b00001001);
    vm_machine_write(m, 0x8, 0x00);
    vm_machine_write(m, 0x9, 0x00);
    vm_machine_write(m, 0xA, 0x00);
    vm_machine_write(m, 0xB, 0x01);
    vm_machine_write(m, 0xC, 0x00);
    vm_machine_write(m, 0xD, 0x01);
    vm_machine_write(m, 0xE, 0x04);

    vm_machine_exec(m, 0x0);

    for (int i = 0; i < NUM_REGISTERS; i++) {
        printf("%2x: %2x\n", i, m->registers[i]);
    }

    vm_machine_destroy(m);
    return 0;
}