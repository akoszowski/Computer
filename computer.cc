#include "computer.h"
#include "processor.h"
#include "memory.h"

Computer::Computer(mem_t size) : memory(size), processor() {}

void Computer::boot(program p) {
	processor.execute(p);
}

void Computer::memory_dump(std::ostream &os) {
	memory.memory_dump(os);
}
