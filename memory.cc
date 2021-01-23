#include "memory.h"

Memory::Memory(mem_t size) : memory(size), mem_size(size), aliases_count(0) {};

void Memory::set_val(const word_t *adr, word_t newVal) {
    if(!valid_address(adr))
        throw IndexOutOfBound();
    memory[*adr] = newVal;
}

const word_t *Memory::get_val(const word_t *adr) const {
    if (!valid_address(adr))
        throw IndexOutOfBound();
    return &memory[*adr];
}

void Memory::add_variable(const char *id, word_t val) {
    if (aliases_count == mem_size)
        throw NotEnoughSpaceForVariables();
    memory[aliases_count] = val;
    aliases.insert(std::make_pair(id, &memory[aliases_count]));
    aliases_count++;
}

const word_t *Memory::find_variable(const char *id) const {
    if (aliases.find(id) == aliases.end())
        throw InvalidIdentifier();
    return aliases.find(id)->second;
}

void Memory::set_ZF(bool val) {
    ZF = val;
}

bool Memory::get_ZF() const {
    return ZF;
}

void Memory::set_SF(bool val) {
    SF = val;
}

bool Memory::get_SF() const {
    return SF;
}

void Memory::memory_dump(std::ostream &os) const {
    for (auto x: memory) {
        os << x << " ";
    }
}

bool Memory::valid_address(const word_t *adr) const {
    return (*adr < (word_t)mem_size && *adr >= 0);
}

