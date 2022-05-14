#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "machine.h"

machine_t *vm_machine_create(uint32_t memsize)
{
    machine_t *m = calloc(1, sizeof(machine_t));
    assert(m != NULL && "failed allocation");

    m->memory = calloc(memsize, sizeof(uint8_t));
    assert(m->memory != NULL && "failed allocation");

    m->memsize = memsize;
    memset(m->registers, 0, sizeof(uint64_t) * NUM_REGISTERS);

    return m;
}

void vm_machine_destroy(machine_t *m)
{
    free(m->memory);
    free(m);
}

uint8_t vm_machine_read(machine_t *m, uint32_t address) /* Page table walk will be here */
{
    assert(address < m->memsize && "address out of bounds");
    return m->memory[address];
}
