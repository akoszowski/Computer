#ifndef OOASM_H
#define OOASM_H

#include "elements.h"
#include <memory>


//FIXME: póki co, być może trzeba będzie to zmienić
using Num_ptr = std::shared_ptr<Num>;
using RVal_ptr = std::shared_ptr<RValue>;
using LVal_ptr = std::shared_ptr<LValue>;
using Instr_ptr = std::shared_ptr<Instruction>;

using program = std::vector<Instr_ptr>;

// Musimy opakować nasze klasy, dzięki zastosowaniu wskaźników możemy sensownie
// wykorzystać naszą hierarchię klas, wpp slicing by na to nie pozwołił.

Num_ptr num(word_t val);

RVal_ptr lea(const char* id);

LVal_ptr mem(RVal_ptr addr);

Instr_ptr data(const char *id, Num_ptr val);

Instr_ptr mov(LVal_ptr dst, RVal_ptr src);

Instr_ptr add(LVal_ptr arg1, RVal_ptr arg2);

Instr_ptr inc(LVal_ptr arg);

Instr_ptr sub(LVal_ptr arg1, RVal_ptr arg2);

Instr_ptr dec(LVal_ptr arg);

Instr_ptr one(LVal_ptr arg);

Instr_ptr onez(LVal_ptr arg);

Instr_ptr ones(LVal_ptr arg);

#endif /* OOASM_H */
