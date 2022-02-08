#include "enigma.h"

void callEnigma(Enigma * enigmaMachine, char* input){
    u8 i = 0;
    while(input[i] != ' ')
        enigmaMachine->inputToEnigma(input[i++]);
}

int main(){
    Enigma enigmaMachine;

    enigmaMachine.switchLetters('A', 'D');
    enigmaMachine.switchLetters('C', 'N');
    enigmaMachine.switchLetters('E', 'T');
    enigmaMachine.switchLetters('F', 'L');
    enigmaMachine.switchLetters('G', 'I');
    enigmaMachine.switchLetters('J', 'V');
    enigmaMachine.switchLetters('K', 'Z');
    enigmaMachine.switchLetters('P', 'U');
    enigmaMachine.switchLetters('Q', 'Y');
    enigmaMachine.switchLetters('W', 'X');

    enigmaMachine.initialize(3, 4, 1, 25, 19, 17, 7, 25, 15, 2);
    //AD CN ET FL GI JV KZ PU QY WX


    //LJPQH SVDWC LYXZQ FXHIU

    callEnigma(&enigmaMachine, (char*) "LJPQHSVDWCLYXZQFXHIUVWDJOBJNZXRCWEOTVNJCIONTFQNSXWISXKHJDAGDJVAKUKVMJAJHSZQQJHZOIAVZOWMSCKASRDN ");


}
