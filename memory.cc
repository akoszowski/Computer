#include "memory.h"

class IndexOutOfBound : std::exception {
public:
    const char *what() const noexcept override {
        return "index out of bound";
    }
};

class NotEnoughSpaceForVariables : std::exception {
public:
    const char *what() const noexcept override {
        return "not enough space for variables";
    }
};

class InvalidIdentifier : public std::exception {
public:
    const char *what() const noexcept override {
        return "invalid identifier";
    }
};


Memory::Memory(mem_t size) : memory(size), mem_size(size), aliases_count(0) {};

void Memory::set_val(mem_t *adr, word_t newVal) {
    if (*adr >= mem_size) //FIXME: to chyba nie jest potrzebne
        throw IndexOutOfBound();
    *adr = newVal;
}

const word_t *Memory::get_val(mem_t *adr) const {
    if (*adr >= mem_size)
        throw IndexOutOfBound();
    return &memory[*adr];
}

void Memory::add_variable(std::string id, word_t val) {
    if (aliases_count == mem_size)
        throw NotEnoughSpaceForVariables();
    memory[aliases_count] = val;
    aliases.insert(std::make_pair(id, &memory[aliases_count]));
    aliases_count++;
}

const word_t *Memory::find_variable(std::string id) const {
    if (aliases.find(id) == aliases.end())
        throw InvalidIdentifier();
    return aliases.find(id)->second;
}

void Memory::memory_dump(std::ostream &os) const {
    for (auto x: memory) {
        os << x << " ";
    }
}

