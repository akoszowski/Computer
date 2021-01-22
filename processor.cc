#include <processor.h>
#include <ooasm.h>

void Processor::execute(program p) {
	for (auto i : p) {
		i->init();
	}
	for (auto i : p) {
		i->execute();
	}
}
