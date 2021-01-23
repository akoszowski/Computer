#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <cstdlib>
#include <utility>
#include <vector>
#include <map>

using word_t = int64_t;
using mem_t = u_int64_t;
using vector_t = std::vector<word_t>;
using map_t = std::map<const char *, word_t *>;

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


class Memory {
public:
    // FIXME: tu trzeba pamiętać o rozbieżności signed vs unsigned
    explicit Memory(mem_t size);

    void set_val(const word_t *adr, word_t val);

    const word_t *get_val(const word_t *adr) const;

    void add_variable(const char *id, word_t val);

    const word_t *find_variable(const char *id) const;

    void set_ZF(bool val);

    bool get_ZF() const;

    void set_SF(bool val);

    bool get_SF() const;

    void memory_dump(std::ostream &os) const;

private:
    vector_t memory;
    map_t aliases;
    mem_t mem_size;
    mem_t aliases_count;

    //FIXME: flagi raczej tutaj
    bool ZF;
    bool SF;

    bool valid_address(const word_t *adr) const;
};

#endif //MEMORY_H
