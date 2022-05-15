#ifndef __DECODE_H__
#define __DECODE_H__

#include "machine.h"

enum {
    MOV_RR,
    MOV_RI,
    MOV_RM,
    MOV_MR,
    ADD_RR,
    ADD_RI,
    ADD_RM,
    ADD_MR,
    ADD_MI,
    ADD_MM,
    SUB_RR,
    SUB_RI,
    SUB_RM,
    SUB_MR,
    SUB_MI,
    SUB_MM,
    MUL_RR,
    MUL_RI,
    MUL_RM,
    MUL_MR,
    MUL_MI,
    MUL_MM,
    S_RR,
    JMP,
    JEQ,
    JNE,
    JGT,
    JLT,
    JGE,
    JLE,
    HLT,
    INT,
    SYS,
    PUSH_R,
    PUSH_I,
    POP,
};

void vm_decode_instr(machine_t *m);

#endif