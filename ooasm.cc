#include "ooasm.h"
#include <memory>

using rVal_ptr = std::shared_ptr<RValue>;
using lVal_ptr = std::shared_ptr<LValue>;
using instr_ptr = std::shared_ptr<Instruction>;

constexpr RValue *num(word_t val) {
    rVal_ptr num_ptr = std::make_shared<Num>(val);
    return num_ptr;
}

constexpr RValue *lea(const char *id) {
    rVal_ptr lea_ptr = std::make_shared<Lea>(Identifier(id));
    return lea_ptr;
}

constexpr LValue *mem(RValue *addr) {
    lVal_ptr mem_ptr = std::make_shared<Mem>(addr);
    return mem_ptr;
}

constexpr Instruction *data(const char *id, Num val) {
    instr_ptr data_ptr = std::make_shared<Declaration>(Identifier(id), Num(val));
    return data_ptr;
}

constexpr Instruction *mov(LValue *dst, RValue *src) {
    instr_ptr mov_ptr = std::make_shared<Mov>(dst, src);
    return mov_ptr;
}

constexpr Instruction *add(LValue *arg1, RValue *arg2) {
    instr_ptr add_ptr = std::make_shared<Add>(arg1, arg2);
    return add_ptr;
}

constexpr Instruction *inc(LValue *arg) {
    instr_ptr inc_ptr = std::make_shared<Add>(arg, Num(1));
    return inc_ptr;
}

constexpr Instruction *sub(LValue *arg1, RValue *arg2) {
    instr_ptr sub_ptr = std::make_shared<Sub>(arg1, arg2);
    return sub_ptr;
}

constexpr Instruction *dec(LValue *arg) {
    instr_ptr dec_ptr = std::make_shared<Sub>(arg, Num(1));
    return dec_ptr;
}

constexpr Instruction *one(LValue *arg) {
    instr_ptr one_ptr = std::make_shared<One>(arg);
    return one_ptr;
}

constexpr Instruction *onez(LValue *arg) {
    instr_ptr onez_ptr = std::make_shared<One>(arg);
    return onez_ptr;
}

constexpr Instruction *ones(LValue *arg) {
    instr_ptr ones_ptr = std::make_shared<One>(arg);
    return ones_ptr;
}

