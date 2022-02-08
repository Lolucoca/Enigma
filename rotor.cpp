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

char turnNumberToChar2(u8 input){
    return (char) input + 65;
}

void Rotor::printRotor(){
    qDebug() << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
    qDebug() << turnNumberToChar2(rotorPosition[0]) << turnNumberToChar2(rotorPosition[1]) << turnNumberToChar2(rotorPosition[2]) << turnNumberToChar2(rotorPosition[3]) << turnNumberToChar2(rotorPosition[4]) << turnNumberToChar2(rotorPosition[5]) << turnNumberToChar2(rotorPosition[6]) << turnNumberToChar2(rotorPosition[7]) << turnNumberToChar2(rotorPosition[8]) << turnNumberToChar2(rotorPosition[9]) << turnNumberToChar2(rotorPosition[10]) << turnNumberToChar2(rotorPosition[11]) << turnNumberToChar2(rotorPosition[12]) << turnNumberToChar2(rotorPosition[13]) << turnNumberToChar2(rotorPosition[14]) << turnNumberToChar2(rotorPosition[15]) << turnNumberToChar2(rotorPosition[16]) << turnNumberToChar2(rotorPosition[17]) << turnNumberToChar2(rotorPosition[18]) << turnNumberToChar2(rotorPosition[19]) << turnNumberToChar2(rotorPosition[20]) << turnNumberToChar2(rotorPosition[21]) << turnNumberToChar2(rotorPosition[22]) << turnNumberToChar2(rotorPosition[23]) << turnNumberToChar2(rotorPosition[24]) << turnNumberToChar2(rotorPosition[25]);
}
