#ifndef COMPUTER_H
#define COMPUTER_H

#include "memory.h"
#include "processor.h"

// TODO:
- dokończyć implementację memory
- implementacja computer, procesor

class Computer {
public:
    Computer(mem_t size);

    ~Computer() = default;

    void boot(program p);

    void memory_dump(std::ostream &os) const;

private:
    Memory *memory;
    Processor *proc;
};

#endif /* COMPUTER_H */