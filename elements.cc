#include "elements.h"

class InvalidIdentifier : public std::exception {
public:
    const char *what() const noexcept override {
        return "invalid identifier";
    }
};

constexpr Identifier::Identifier(const char *id) : _id(id) {};

std::string Identifier::get_id() const {
    return _id;
}

constexpr bool Identifier::is_valid(std::string id) {
    static_assert(id.size() < 1 || id.size() > 10, "invalid identifier");
}

Num::Num(word_t val) {
    _val = val;
};

word_t *Num::evaluate(Memory *memory) {
    return &_val;
}

Lea::Lea(Identifier id) : _id(id) {};

// FIXME: class Memory powinna rzucać wszelakie wyjątki
word_t *Lea::evaluate(Memory *memory) {
    if ((_val = memory->find_variable(_id.get_id())) != nullptr) {
        return _val;
    } else {
        throw InvalidIdentifier();
    }
}

Mem::Mem(RValue *addr) : _addr(addr) {};

// FIXME: klasa memory powinna rzucać "index out of bound"
word_t *Mem::evaluate(Memory *memory) {
    _val = memory->get_val(_addr);
    return _val;
}


// FIXME: klasa memory powinna sprawdzać, czy mamy dostatecznie wiele pamięci
Declaration::Declaration(Identifier id, Num val): _id(id), _val(val) {};

void Declaration::execute(Memory *memory) {
    memory->add_variable(_id.get_id(), _val.evaluate());
}

Operation::Operation(LValue *arg1, RValue *arg2): _arg1(arg1), _arg2(arg2) {};

Mov::Mov(LValue *arg1, RValue *arg2): Operation(arg1, arg2) {};

void Mov::execute(Memory *memory) {
    memory->set_val(_arg1->evaluate(), *_arg2->evaluate());
}

// FIXME: wyjątki !!! w memory.h + odpowiednie flagi
Add::Add(LValue *arg1, RValue *arg2): Operation(arg1, arg2) {};

void Add::execute(Memory *memory) {
    memory->set_val(_arg1->evaluate(), *_arg1->evaluate() + *_arg2->evaluate());
}

Sub::Sub(LValue *arg1, RValue *arg2): Operation(arg1, arg2) {};

void Sub::execute(Memory *memory) {
    memory->set_val(_arg1->evaluate(), *_arg1->evaluate() - *_arg2->evaluate());
}

Assignment::Assignment(LValue *arg): _arg(arg) {};

One::One(LValue *arg): Assignment(arg) {};

void One::execute(Memory *memory) {
    memory->set_val(_arg->evaluate(), Num(1).evaluate());
}

Onez::Onez(LValue *arg): Assignment(arg) {};

void Onez::execute(Memory *memory) {
    if (memory->ZF)
        memory->set_val(_arg->evaluate(), Num(1));
}

Ones::Ones(LValue *arg): Assignment(arg) {};

void Ones::execute(Memory *memory) {
    if (memory->SF)
        memory->set_val(_arg->evaluate(), Num(1));
}










