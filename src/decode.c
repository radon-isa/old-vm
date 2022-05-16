#include <assert.h>
#include "decode.h"
#include <stdio.h>
#include "machine.h"

uint8_t vm_decode_consume(machine_t *m)
{
    uint64_t ip = m->registers[INSTR_PTR]++;
    return m->memory[ip];
}

uint64_t vm_decode_consume_value(machine_t *m, uint8_t size)
{
    uint64_t value = 0;

    // Radon is big-endian, so we need to shift values starting
    // from the most significant byte
    for (uint8_t i = size; i > 0; i--) {
        value |= (vm_decode_consume(m) << ((i - 1) * 8));
    }

    return value;
}

// MSN/LSN: Most/Less Significant Nibble 
#define MSN(v) (v >> 4)
#define LSN(v) (v & 0xF)

// MSC/LSC: Most/Less Significant Crumb (2 bit values)
#define MSC(v) (v >> 2)
#define LSC(v) (v & 0x3)

// We use computed gotos for efficient opcode execution
// Check references :>
#define DISPATCH() goto *dispatch_table[vm_decode_consume(m)]

void vm_decode_instr(machine_t *m)
{
    uint8_t instr[4];

    static void *dispatch_table[] = {
        &&MOV_RR,
        &&MOV_RI,
        &&MOV_RM,
        &&MOV_MR,
        &&HLT,
    };

    DISPATCH();
    while (1) {
        MOV_RR:
            printf("MOV_RR %x\n", m->registers[INSTR_PTR]);
            instr[1] = vm_decode_consume(m);
            m->registers[MSN(instr[1])] = m->registers[LSN(instr[1])];
            DISPATCH();
        MOV_RI:
            printf("MOV_RI\n");
            instr[1] = vm_decode_consume(m);
            m->registers[MSN(instr[1])] = vm_decode_consume_value(m, LSN(instr[1]));
            DISPATCH();
        MOV_RM:
            printf("MOV_RM\n");
            instr[1] = vm_decode_consume(m);
            m->registers[MSN(instr[1])] = vm_machine_read_value(m, vm_decode_consume_value(m, 4) + (LSC(LSN(instr[1])) ? vm_decode_consume_value(m, 2) : 0), MSC(LSN(instr[1]))); 
            DISPATCH();
        MOV_MR:
            instr[1] = vm_decode_consume(m);
            printf("Opcode 3: %x\n", instr[1]);
            DISPATCH();
        HLT:
            printf("HLT\n");
            break;
    }
}