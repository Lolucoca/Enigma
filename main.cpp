#include "enigma.h"

int main(){
    Enigma enigmaMachine;
    enigmaMachine.initialize(1, 2, 3, 0, 0, 0, 2);

    enigmaMachine.inputToEnigma('M');
    enigmaMachine.inputToEnigma('T');
    enigmaMachine.inputToEnigma('N');
    enigmaMachine.inputToEnigma('C');
    enigmaMachine.inputToEnigma('Z');


}
