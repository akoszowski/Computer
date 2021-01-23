#ifndef OOASM_H
#define OOASM_H

#include "elements.h"

//FIXME: póki co, być może trzeba będzie to zmienić
using program = std::vector<Instruction*>;

// Musimy opakować nasze klasy, dzięki zastosowaniu wskaźników możemy sensownie
// wykorzystać naszą hierarchię klas, wpp slicing by na to nie pozwołił.

Num *num(word_t val);

RValue *lea(const char* id);

LValue *mem(RValue *addr);

Instruction *data(const char *id, Num *val);

Instruction *mov(LValue *dst, RValue *src);

Instruction *add(LValue *arg1, RValue *arg2);

Instruction *inc(LValue *arg);

Instruction *sub(LValue *arg1, RValue *arg2);

Instruction *dec(LValue *arg);

Instruction *one(LValue *arg);

Instruction *onez(LValue *arg);

Instruction *ones(LValue *arg);

#endif /* OOASM_H */
