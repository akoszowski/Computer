#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <cstdlib>
#include <vector>


using word_t = int64_t;
using mem_t = std::vector<int64_t>;

class Memory {
public:
    // FIXME: tu trzeba pamiętać o rozbieżności signed vs unsigned
    Memory(u_int64_t size);

    void setVal(u_int64_t adr, int64_t newVal);

    word_t getVal(u_int64_t adr);

    void memory_dump(std::ostream& os);

private:
    mem_t mem;

};
#endif //MEMORY_H
