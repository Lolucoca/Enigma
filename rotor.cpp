#include "rotor.h"

Rotor::Rotor()
{

}

void Rotor::initialize(u8 *rotorConfiguration){
    memcpy(rotorPosition, rotorConfiguration, ALPHABETSIZE);
    populateReflections();
    rotateStatus = 0;
    breakPosition = 0;
}

void Rotor::populateReflections(){
    for(u8 i = 0; i < ALPHABETSIZE; i++){
        reflectionPosition[rotorPosition[i]] = i;
    }
}

u8 Rotor::rotate(){
    rotateStatus += 1;
    rotateStatus %= 26;

    u8 temp = rotorPosition[0];
    memcpy(rotorPosition, rotorPosition + 1, ALPHABETSIZE - 1);
    rotorPosition[ALPHABETSIZE - 1] = temp;
    for(u8 i = 0; i < ALPHABETSIZE; i++) //Rotate the second half
        if(rotorPosition[i] > 0)
            rotorPosition[i] -= 1;
        else
            rotorPosition[i] = ALPHABETSIZE - 1;

    populateReflections();

    //qDebug() << rotateStatus;

    if(rotateStatus == breakPosition){

        //rotateStatus = 0;
        return 1; //Rotiere den nächsten Rotor
    }

    return 0;
}

u8 Rotor::passSignal(u8 input){
    //populateReflections();
    return rotorPosition[input];
}

u8 Rotor::reverseSignal(u8 input){
    return reflectionPosition[input];
}

void Rotor::setBreakPosition(u8 brk){
    breakPosition = brk;
    rotateStatus = 26 - (brk - 1); //Weil wir bei 0 anfangen zu zählen
}

u8 Rotor::getRotorPosition(){
    return rotateStatus;
}

