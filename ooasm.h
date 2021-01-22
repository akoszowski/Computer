#ifndef OOASM_H
#define OOASM_H

#include "elements.h"

//FIXME: póki co, być może trzeba będzie to zmienić
using program = std::vector<Instruction*>;

// Musimy opakować nasze klasy, dzięki zastosowaniu wskaźników możemy sensownie
// wykorzystać naszą hierarchię klas, wpp slicing by na to nie pozwołił.

// FIXME: wywalić
constexpr RValue *num(word_t val);

constexpr RValue *lea(const char* id);

constexpr LValue *mem(RValue *addr);

constexpr Instruction *data(const char *id, Num val);

constexpr Instruction *mov(LValue *dst, RValue *src);

constexpr Instruction *add(LValue *arg1, RValue *arg2);

constexpr Instruction *inc(LValue *arg);

constexpr Instruction *sub(LValue *arg1, RValue *arg2);

constexpr Instruction *dec(LValue *arg);

constexpr Instruction *one(LValue *arg);

constexpr Instruction *onez(LValue *arg);

constexpr Instruction *ones(LValue *arg);

#endif /* OOASM_H */
