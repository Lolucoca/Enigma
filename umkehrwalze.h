#ifndef UMKEHRWALZE_H
#define UMKEHRWALZE_H

#include "rotor.h"

class Umkehrwalze
{
public:
    Umkehrwalze();
    void initialize(u8 * ukwConfiguration);
    u8 passSignal(u8 input);
private:
    u8 ukwPosition[ALPHABETSIZE];
};

#endif // UMKEHRWALZE_H
