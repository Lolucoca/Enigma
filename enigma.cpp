#include "enigma.h"

u8 rotorI[] = {4, 10, 12, 5, 11, 6, 3, 16, 21, 25, 13, 19, 14, 22, 24, 7, 23, 20, 18, 15, 0, 8, 1, 17, 2, 9};
u8 rotorII[] = {0, 9, 3, 10, 18, 8, 17, 20, 23, 1, 11, 7, 22, 19, 12, 2, 16, 6, 25, 13, 15, 24, 5, 21, 14, 4};
u8 rotorIII[] = {1, 3, 5, 7, 9, 11, 2, 15, 17, 19, 23, 21, 25, 13, 24, 4, 8, 22, 6, 0, 10, 12, 20, 18, 16, 14};
u8 rotorIV[] = {4, 18, 14, 21, 15, 25, 9, 0, 24, 16, 20, 8, 17, 7, 23, 11, 13, 5, 19, 6, 10, 3, 2, 12, 22, 1};
u8 rotorV[] = {21, 25, 1, 17, 6, 8, 19, 24, 20, 15, 18, 3, 13, 7, 11, 23, 0, 22, 12, 9, 16, 14, 5, 4, 2, 10};

u8 ukwA[] = {4, 9, 12, 25, 0, 11, 24, 23, 21, 1, 22, 5, 2, 17, 16, 20, 14, 13, 19, 18, 15, 8, 10, 7, 6, 3};
u8 ukwB[] = {24, 17, 20, 7, 16, 18, 11, 3, 15, 23, 13, 6, 14, 10, 12, 8, 4, 1, 5, 25, 2, 22, 21, 9, 0, 19};
u8 ukwC[] = {5, 21, 15, 9, 8, 0, 14, 24, 4, 3, 17, 25, 23, 22, 6, 2, 19, 10, 20, 16, 18, 1, 13, 12, 7, 11};

u8 frontPanelPosition[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};

u8 rotorABreakPosition = 16;
u8 rotorBBreakPosition = 26;
u8 rotorCBreakPosition = 8;

Enigma::Enigma()
{

}

char turnNumberToChar(u8 input){
    return (char) input + 65;
}

u8 turnCharToNumber(char input){
    return (u8) input - 65;
}

u8 * selectRotorConfiguration(u8 config){
    switch(config){
        case 1: return rotorI;
        case 2: return rotorII;
        case 3: return rotorIII;
        case 4: return rotorIV;
        case 5: return rotorV;
        default: return rotorI;
    }
}

u8 * selectUmkehrwalzeConfiguration(u8 config){
    switch(config){
        case 1: return ukwA;
        case 2: return ukwB;
        case 3: return ukwC;
        default: return ukwA;
    }
}

void Enigma::initialize(u8 firstRotor, u8 secondRotor, u8 thirdRotor, u8 rotorAPosition, u8 rotorBPosition, u8 rotorCPosition, u8 umkehrwalze){


    rotorA.initialize(selectRotorConfiguration(firstRotor));
    rotorA.setBreakPosition(rotorABreakPosition);
    rotorB.initialize(selectRotorConfiguration(secondRotor));
    rotorB.setBreakPosition(rotorBBreakPosition);
    rotorC.initialize(selectRotorConfiguration(thirdRotor));
    rotorC.setBreakPosition(rotorCBreakPosition);
    walze.initialize(selectUmkehrwalzeConfiguration(umkehrwalze));
    panel.initialize(frontPanelPosition);

    for(u8 i = 0; i < rotorAPosition; i++)
        rotorA.rotate();
    for(u8 i = 0; i < rotorBPosition; i++)
        rotorB.rotate();
    for(u8 i = 0; i < rotorCPosition; i++)
        rotorC.rotate();

}

void Enigma::inputToEnigma(char input){

    u8 inChar = turnCharToNumber(input);

    u8 needToRotateB = rotorA.rotate();
    if(needToRotateB){
        u8 needToRotateC = rotorB.rotate();
        if(needToRotateC){
            rotorC.rotate();
        }
    }

    u8 frontPanelRes = panel.passSignal(inChar);
    u8 rotorARes = rotorA.passSignal(frontPanelRes);
    u8 rotorBRes = rotorB.passSignal(rotorARes);
    u8 rotorCRes = rotorC.passSignal(rotorBRes);
    u8 ukwRes = walze.passSignal(rotorCRes);
    u8 rotorCRef = rotorC.reverseSignal(ukwRes);
    u8 rotorBRef = rotorB.reverseSignal(rotorCRef);
    u8 rotorARef = rotorA.reverseSignal(rotorBRef);
    u8 frontPanelRef = panel.reverseSignal(rotorARef);
    qDebug() << "Input: " << turnNumberToChar(inChar) << "Front Panel: " << turnNumberToChar(frontPanelRes) << " Rotor A: " << turnNumberToChar(rotorARes) << " Rotor B: " << turnNumberToChar(rotorBRes) << " Rotor C: " << turnNumberToChar(rotorCRes)<< " Walze: " << turnNumberToChar(ukwRes)<< " Rotor C Reverse: " << turnNumberToChar(rotorCRef)<< " Rotor B Reverse: " << turnNumberToChar(rotorBRef)<< " Rotor A Reverse: " << turnNumberToChar(rotorARef) << "Output: " << turnNumberToChar(frontPanelRef);

}
