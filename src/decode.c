#include <assert.h>
#include "decode.h"

uint8_t vm_decode_consume(machine_t *m)
{
    uint64_t ip = m->registers[INSTR_PTR]++;
    return m->memory[ip];
}

void vm_decode_instr(machine_t *m)
{
    uint8_t instr[4];

    switch ((instr[0] = vm_decode_consume(m))) {
    case MOV_RR:
        instr[1] = vm_decode_consume(m);
        break;
    default:
        assert(0 && "Invalid instruction");
        break;
    }
}