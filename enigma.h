#ifndef ENIGMA_H
#define ENIGMA_H

#include "rotor.h"
#include "umkehrwalze.h"
#include "frontpanel.h"

class Enigma
{
public:
    Enigma();
    void initialize(u8 rotorA, u8 rotorB, u8 rotorC, u8 rotorAPosition, u8 rotorBPosition, u8 rotorCPosition, u8 walze);
    void inputToEnigma(char input);
private:
    Rotor rotorA;
    Rotor rotorB;
    Rotor rotorC;
    Umkehrwalze walze;
    FrontPanel panel;
};

#endif // ENIGMA_H
