#include "ooasm.h"
#include <memory>

using rVal_ptr = std::shared_ptr<RValue>;
using lVal_ptr = std::shared_ptr<LValue>;
using instr_ptr = std::shared_ptr<Instruction>;

Num *num(word_t val) {
    std::shared_ptr<Num> num_ptr = std::make_shared<Num>(val);
    return num_ptr.get();
}

RValue *lea(const char *id) {
    rVal_ptr lea_ptr = std::make_shared<Lea>(Identifier(id));
    return lea_ptr.get();
}

LValue *mem(RValue *addr) {
    lVal_ptr mem_ptr = std::make_shared<Mem>(addr);
    return mem_ptr.get();
}

Instruction *data(const char *id, Num *val) {
    instr_ptr data_ptr = std::make_shared<Declaration>(Identifier(id), val);
    return data_ptr.get();
}

Instruction *mov(LValue *dst, RValue *src) {
    instr_ptr mov_ptr = std::make_shared<Mov>(dst, src);
    return mov_ptr.get();
}

Instruction *add(LValue *arg1, RValue *arg2) {
    instr_ptr add_ptr = std::make_shared<Add>(arg1, arg2);
    return add_ptr.get();
}

Instruction *inc(LValue *arg) {
    instr_ptr inc_ptr = std::make_shared<Add>(arg, num(1));
    return inc_ptr.get();
}

Instruction *sub(LValue * arg1, RValue * arg2) {
    instr_ptr sub_ptr = std::make_shared<Sub>(arg1, arg2);
    return sub_ptr.get();
}

Instruction *dec(LValue * arg) {
    instr_ptr dec_ptr = std::make_shared<Sub>(arg, num(1));
    return dec_ptr.get();
}

Instruction *one(LValue * arg) {
    instr_ptr one_ptr = std::make_shared<One>(arg);
    return one_ptr.get();
}

Instruction *onez(LValue * arg) {
    instr_ptr onez_ptr = std::make_shared<Onez>(arg);
    return onez_ptr.get();
}

Instruction *ones(LValue * arg) {
    instr_ptr ones_ptr = std::make_shared<Ones>(arg);
    return ones_ptr.get();
}

