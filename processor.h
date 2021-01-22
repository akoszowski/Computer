#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "ooasm.h"
#include "memory.h"

// Klasa realizująca/ wykonująca program
class Processor {
public:
    Processor() =  default;

    ~Processor() = default;

    // FIXME: Najpierw wczytujemmy zmienne, potem realizujemy właściwe instrukcje.
    void execute(program &p, Memory *memory);
};

#endif // PROCESSOR_H
