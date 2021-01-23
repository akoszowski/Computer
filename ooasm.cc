#include "ooasm.h"
#include <iostream>

Num_ptr num(word_t val) {
    Num_ptr num_ptr = std::make_shared<Num>(val);
    return num_ptr;
}

RVal_ptr lea(const char *id) {
    RVal_ptr lea_ptr = std::make_shared<Lea>(Identifier(id));
    return lea_ptr;
}

LVal_ptr mem(RVal_ptr addr) {
    LVal_ptr mem_ptr = std::make_shared<Mem>(addr);
    return mem_ptr;
}

Instr_ptr data(const char *id, Num_ptr val) {
    Instr_ptr data_ptr = std::make_shared<Declaration>(Identifier(id), val);
    return data_ptr;
}

Instr_ptr mov(LVal_ptr dst, RVal_ptr src) {
    Instr_ptr mov_ptr = std::make_shared<Mov>(dst, src);
    return mov_ptr;
}

Instr_ptr add(LVal_ptr arg1, RVal_ptr arg2) {
    Instr_ptr add_ptr = std::make_shared<Add>(arg1, arg2);
    return add_ptr;
}

Instr_ptr inc(LVal_ptr arg) {
    Instr_ptr inc_ptr = std::make_shared<Add>(arg, num(1));
    return inc_ptr;
}

Instr_ptr sub(LVal_ptr arg1, RVal_ptr arg2) {
    Instr_ptr sub_ptr = std::make_shared<Sub>(arg1, arg2);
    return sub_ptr;
}

Instr_ptr dec(LVal_ptr arg) {
    Instr_ptr dec_ptr = std::make_shared<Sub>(arg, num(1));
    return dec_ptr;
}

Instr_ptr one(LVal_ptr arg) {
    Instr_ptr one_ptr = std::make_shared<One>(arg);
    return one_ptr;
}

Instr_ptr onez(LVal_ptr arg) {
    Instr_ptr onez_ptr = std::make_shared<Onez>(arg);
    return onez_ptr;
}

Instr_ptr ones(LVal_ptr arg) {
    Instr_ptr ones_ptr = std::make_shared<Ones>(arg);
    return ones_ptr;
}

