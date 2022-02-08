#ifndef ENIGMA_H
#define ENIGMA_H

#include "rotor.h"
#include "umkehrwalze.h"
#include "frontpanel.h"

class Enigma
{
public:
    Enigma();
    void initialize(u8 firstRotor, u8 secondRotor, u8 thirdRotor, u8 rotorAPosition, u8 rotorBPosition, u8 rotorCPosition, u8 ringSettingA, u8 ringSettingB, u8 ringSettingC, u8 umkehrwalze);
    void inputToEnigma(char input);
    void switchLetters(char A, char B);
private:
    Rotor rotorA;
    Rotor rotorB;
    Rotor rotorC;
    Umkehrwalze walze;
    FrontPanel panel;
};

#endif // ENIGMA_H
