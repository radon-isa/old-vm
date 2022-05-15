#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "machine.h"
#include "decode.h"

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

uint8_t vm_machine_write(machine_t *m, uint32_t address, uint8_t value) /* Page table walk will be here */
{
    assert(address < m->memsize && "address out of bounds");
    return (m->memory[address] = value);
}

uint64_t vm_machine_read_value(machine_t *m, uint32_t address, uint8_t size)
{
    assert(address < m->memsize && "address out of bounds");
    uint64_t value;
    uint8_t offset;

    for (uint8_t i = size, offset = 0; i > 0; i--, offset++) {
        value |= (vm_machine_read(m, address + offset) << ((i - 1) * 8));
    }

    return value;
}

void vm_machine_exec(machine_t *m, uint32_t start_address)
{
    assert(start_address < m->memsize && "address out of bounds");
    
    m->registers[INSTR_PTR] = start_address;
    vm_decode_instr(m);
}