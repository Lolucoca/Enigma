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

    //Rotors from right to left (3, 4, 1), initial word from right to left (RTZ), rotor spin setting from right to left (16 26 8) and umkehrwalze setting (2 = B)

    enigmaMachine.initialize(3, 4, 1, 25, 19, 17, 7, 25, 15, 2);


    callEnigma(&enigmaMachine, (char*) "LJPQHSVDWCLYXZQFXHIUVWDJOBJNZXRCWEOTVNJCIONTFQNSXWISXKHJDAGDJVAKUKVMJAJHSZQQJHZOIAVZOWMSCKASRDNXKKSRFHCXCMPJGXYIJCCKISYYSHETXVVOVDQLZYTNJXNUWKZRXUJFXMBDIBRVMJKRHTCUJQPTEEIYNYNJBEAQJCLMUODFWMARQCFOBWN ");


}
