#ifndef ELEMENTS_H
#define ELEMENTS_H

#include "memory.h"

// Identyfikator zmiennej
// 1-10 dowolnych znaków.
class Identifier {
public:
    constexpr Identifier(const char *id);

    std::string get_id() const;

private:
    std::string _id;

    constexpr bool is_valid(std::string id);
};

// FIXME: w liściach dałem normalne dtor-y
// FIXME: Num  i Lea zwracają word_t de facto, Mem z kolei adres, czyli word_t*.
class RValue {
public:
    constexpr RValue();

    virtual ~RValue() = default;

    virtual word_t *evaluate(Memory *memory) = 0;

protected:
    word_t *_val;
};

class LValue : public RValue {
public:
    constexpr LValue();

    virtual ~LValue() = default;

    virtual word_t *evaluate(Memory *memory) = 0;
};

class Num : public RValue {
public:
    constexpr Num(word_t val);

    ~Num() = default;

    word_t *evaluate(Memory *memory) override;
};

class Lea : public RValue {
public:
    constexpr Lea(Identifier id);

    ~Lea() = default;

    word_t *evaluate(Memory *memory) override;

private:
    Identifier _id;
};

class Mem : public LValue {
public:
    constexpr Mem(RValue *addr);

    ~Mem() = default;

    word_t *evaluate(Memory *memory) override;

private:
    RValue *_addr;
};


class Instruction {
public:
    constexpr Instruction();

    virtual ~Instruction() = default;

    virtual void execute(Memory *memory) = 0;
};

class Declaration : public Instruction {
public:
    constexpr Declaration(Identifier id, Num val);

    ~Declaration() = default;

    void execute(Memory *memory) override;

private:
    Identifier _id;
    Num _val;
};

class Operation : public Instruction {
public:
    constexpr Operation(LValue *arg1, RValue *arg2);

    virtual ~Operation() = default;

    virtual void execute(Memory *memory) = 0;

protected:
    LValue *_arg1;
    RValue *_arg2;
};

class Mov: public Operation {
public:
    constexpr Mov();

    ~Mov() = default;

    void execute(Memory *memory) override;
};

// FIXME tu nie wiem do końca czy takie constructory będą ok, czy może być default???
class Add : public Operation {
public:
    constexpr Add();

    ~Add() = default;

    void execute(Memory *memory) override;
};

class Sub : public Operation {
public:
    constexpr Sub();

    ~Sub() = default;

    void execute(Memory *memory) override;
};

class Assignment : public Instruction {
public:
    constexpr Assignment(LValue *arg);

    virtual void execute(Memory *memory) = 0;

protected:
    LValue *_arg;
};

class One : public Assignment {
public:
    constexpr One();

    void execute(Memory *memory) override;
};

class Onez : public Assignment {
public:
    constexpr Onez();

    void execute(Memory *memory) override;
};

class Ones : public Assignment {
public:
    constexpr Ones();

    void execute(Memory *memory) override;
};

#endif // ELEMENTS_H
