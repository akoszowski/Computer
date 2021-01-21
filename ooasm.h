#ifndef OOASM_H
#define OOASM_H

#include "memory.h"
#include <string>


// Identyfikator zmiennej
// 1-10 dowolnych znaków.
class Identifier {
public:
    constexpr Identifier(const char* id);

    std::string get_id() const;

private:
    std::string _id;

    constexpr bool is_valid(std::string id);
};

// Tu mamy Num i Lea, które dają nam word_t.
class RValue {
public:
    constexpr RValue() = default;

    virtual ~RValue() = default;

    virtual word_t* evaluate(Memory* memory) = 0;

protected:
    word_t _val;
};

class LValue: public RValue {
public:
    constexpr LValue() = default;

    virtual ~LValue() = default;

    virtual word_t* evaluate(Memory* memory) = 0;
};

class Num: public RValue {
public:
    constexpr Num(word_t n);

    virtual ~Num() = default;

    word_t* evaluate(Memory* memory) override;
};

class Lea: public RValue {
    constexpr Lea(Identifier id);

    virtual ~Lea() = default;

    word_t* evaluate(Memory *memory) override;
};

class Mem: public LValue {
    constexpr Mem(RValue r_val);

    virtual ~Mem() = default;

    word_t* evaluate(Memory *memory) override;
};

#endif /* OOASM_H */
