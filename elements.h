#ifndef ELEMENTS_H
#define ELEMENTS_H

#include "memory.h"

// Identyfikator zmiennej
// 1-10 dowolnych znaków.
class Identifier {
public:
    explicit Identifier(const char *id);

    const char *get_id() const;

private:
    const char *_id;

    bool is_valid();
};

// FIXME: w liściach dałem normalne dtor-y
// FIXME: Num  i Lea zwracają word_t de facto, Mem z kolei adres, czyli word_t*.
class RValue {
public:
    RValue() = default;

    virtual ~RValue() = default;

    virtual const word_t *evaluate(Memory *memory) = 0;
};

using RVal_ptr = std::shared_ptr<RValue>;

class LValue : public RValue {
public:
    LValue() = default;

    virtual ~LValue() = default;

    virtual const word_t *evaluate(Memory *memory) = 0;
};

using LVal_ptr = std::shared_ptr<LValue>;

class Num : public RValue {
public:
    explicit Num(word_t val);

    ~Num() = default;

    const word_t *evaluate(Memory *memory) override;

private:
    word_t _val;
};

using Num_ptr = std::shared_ptr<Num>;

class Lea : public RValue {
public:
    explicit Lea(Identifier id);

    ~Lea() = default;

    const word_t *evaluate(Memory *memory) override;

private:
    Identifier _id;
};

class Mem : public LValue {
public:
    explicit Mem(RVal_ptr addr);

    ~Mem() = default;

    const word_t *evaluate(Memory *memory) override;

private:
    RVal_ptr _addr;
};


class Instruction {
public:
    Instruction() = default;

    virtual ~Instruction() = default;

    virtual void execute(Memory *memory) = 0;

    virtual void init(Memory *memory) = 0;
};

using Instr_ptr = std::shared_ptr<Instruction>;

class Declaration : public Instruction {
public:
    Declaration(Identifier id, Num_ptr val);

    ~Declaration() = default;

    void execute(Memory *memory) override;

    void init(Memory *memory) override;

private:
    Identifier _id;
    Num_ptr _val;
};

class Operation : public Instruction {
public:
    Operation(LVal_ptr arg1, RVal_ptr arg2);

    virtual ~Operation() = default;

    virtual void execute(Memory *memory) = 0;

    void init(Memory *memory) override;

protected:
    LVal_ptr _arg1;
    RVal_ptr _arg2;
};

class Mov : public Operation {
public:
    Mov(LVal_ptr arg1, RVal_ptr arg2);

    ~Mov() = default;

    void execute(Memory *memory) override;
};

// FIXME tu nie wiem do końca czy takie constructory będą ok, czy może być default???
class Add : public Operation {
public:
    Add(LVal_ptr arg1, RVal_ptr arg2);

    ~Add() = default;

    void execute(Memory *memory) override;
};

class Sub : public Operation {
public:
    Sub(LVal_ptr arg1, RVal_ptr arg2);

    ~Sub() = default;

    void execute(Memory *memory) override;
};

class Assignment : public Instruction {
public:
    explicit Assignment(LVal_ptr arg);

    virtual void execute(Memory *memory) = 0;

    void init(Memory *memory) override;

protected:
    LVal_ptr _arg;
};

class One : public Assignment {
public:
    explicit One(LVal_ptr arg);

    void execute(Memory *memory) override;
};

class Onez : public Assignment {
public:
    explicit Onez(LVal_ptr arg);

    void execute(Memory *memory) override;
};

class Ones : public Assignment {
public:
    explicit Ones(LVal_ptr arg);

    void execute(Memory *memory) override;
};

#endif // ELEMENTS_H
