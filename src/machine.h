#ifndef __MACHINE_H__
#define __MACHINE_H__

#include <stdint.h>

enum {
    ZERO,
    INSTR_PTR,
    STACK_BASE,
    STACK_PTR,
    PAGE_TABLE_PTR,
    TRAP_HANDLER_PTR,
    INT_HANDLER_PTR,
    RET_ADDR,
    R1,
    R2,
    R3,
    R4,
    R5,
    R6,
    R7,
    R8,
    NUM_REGISTERS,
};

typedef struct {
    uint8_t *memory;
    uint32_t memsize;
    uint64_t registers[NUM_REGISTERS];
} machine_t;

machine_t *vm_machine_create(uint32_t memsize);
void vm_machine_destroy(machine_t *m);
uint8_t vm_machine_read(machine_t *m, uint32_t address);
uint8_t vm_machine_write(machine_t *m, uint32_t address, uint8_t value);
uint64_t vm_machine_read_value(machine_t *m, uint32_t address, uint8_t size);
void vm_machine_exec(machine_t *m, uint32_t start_address);

#endif