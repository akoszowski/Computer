#include "processor.h"

void Processor::execute(program &p, Memory *memory) {
	for (auto i : p) {
		i->init(memory);
	}
	for (auto i : p) {
		i->execute(memory);
	}
}
