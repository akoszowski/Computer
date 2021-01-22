#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "ooasm.h"

// Klasa realizująca/ wykonująca program
class Processor {
public:
    Processor() =  default;

    ~Processor() = default;

    // FIXME: Najpierw wczytujemmy zmienne, potem realizujemy właściwe instrukcje.
    void execute(program p);
};

#endif // PROCESSOR_H
