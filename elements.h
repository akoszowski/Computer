#ifndef ELEMENTS_H
#define ELEMENTS_H

#include "memory.h"

// Identyfikator zmiennej
// 1-10 dowolnych znaków.
class Identifier {
public:
    constexpr explicit Identifier(const char *id);

    std::string get_id() const;

private:
    const std::string _id;

    constexpr void is_valid(const char *id);
};

// FIXME: w liściach dałem normalne dtor-y
// FIXME: Num  i Lea zwracają word_t de facto, Mem z kolei adres, czyli word_t*.
class RValue {
public:
    RValue() = default;

    virtual ~RValue() = default;

    virtual word_t *evaluate(Memory *memory) = 0;

protected:
    word_t *_val;
};

class LValue : public RValue {
public:
    LValue() = default;

    virtual ~LValue() = default;

    virtual word_t *evaluate(Memory *memory) = 0;
};

class Num : public RValue {
public:
    explicit Num(word_t val);

    ~Num() = default;

    word_t *evaluate(Memory *memory) override;
};

class Lea : public RValue {
public:
    explicit Lea(Identifier id);

    ~Lea() = default;

    word_t *evaluate(Memory *memory) override;

private:
    Identifier _id;
};

class Mem : public LValue {
public:
    explicit Mem(RValue *addr);

    ~Mem() = default;

    word_t *evaluate(Memory *memory) override;

private:
    RValue *_addr;
};


class Instruction {
public:
    Instruction() = default;

    virtual ~Instruction() = default;

    virtual void execute(Memory *memory) = 0;

    virtual void init(Memory *memory) = 0;
};

class Declaration : public Instruction {
public:
    Declaration(Identifier id, Num val);

    ~Declaration() = default;

    void execute(Memory *memory) override;

    void init(Memory *memory) override;

private:
    Identifier _id;
    Num _val;
};

class Operation : public Instruction {
public:
    Operation(LValue *arg1, RValue *arg2);

    virtual ~Operation() = default;

    virtual void execute(Memory *memory) = 0;

    void init(Memory *memory) override;

protected:
    LValue *_arg1;
    RValue *_arg2;
};

class Mov: public Operation {
public:
    Mov(LValue *arg1, RValue *arg2);

    ~Mov() = default;

    void execute(Memory *memory) override;
};

// FIXME tu nie wiem do końca czy takie constructory będą ok, czy może być default???
class Add : public Operation {
public:
    Add(LValue *arg1, RValue *arg2);

    ~Add() = default;

    void execute(Memory *memory) override;
};

class Sub : public Operation {
public:
    Sub(LValue *arg1, RValue *arg2);

    ~Sub() = default;

    void execute(Memory *memory) override;
};

class Assignment : public Instruction {
public:
    explicit Assignment(LValue *arg);

    virtual void execute(Memory *memory) = 0;

protected:
    LValue *_arg;
};

class One : public Assignment {
public:
    explicit One(LValue *arg);

    void execute(Memory *memory) override;
};

class Onez : public Assignment {
public:
    explicit Onez(LValue *arg);

    void execute(Memory *memory) override;
};

class Ones : public Assignment {
public:
    explicit Ones(LValue *arg);

    void execute(Memory *memory) override;
};

#endif // ELEMENTS_H
