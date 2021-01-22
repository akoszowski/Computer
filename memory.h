#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>

using word_t = int64_t;
using mem_t = u_int64_t;
using vector_t = std::vector<word_t>;
using map_t = std::map<std::string, mem_t>;

// FIXME: tu na pewno będzie dodać parę metod, wyjdzie w praniu
class Memory {
public:
    // FIXME: tu trzeba pamiętać o rozbieżności signed vs unsigned
    Memory(mem_t size);

    void set_val(mem_t *adr, word_t newVal);

    word_t get_val(mem_t *adr);

    void memory_dump(std::ostream& os);

private:
    vector_t memory;
    map_t aliases;
    mem_t mem_size;
    mem_t aliases_count;

    //FIXME: flagi raczej tutaj
    bool ZF;
    bool SF;
};
#endif //MEMORY_H
