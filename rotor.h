#ifndef ROTOR_H
#define ROTOR_H
#include "inttypes.h"
#include "qdebug.h"
#include <string.h>
#define ALPHABETSIZE 26


typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

//Rotor hat Position an der Umgeschaltet wird
class Rotor
{
public:
    Rotor();
    void initialize(u8 * rotorConfiguration);
    u8 rotate();
    u8 passSignal(u8 input);
    u8 reverseSignal(u8 input);
    void setBreakPosition(u8 brk);
private:
    void populateReflections();
    u8 rotorPosition[ALPHABETSIZE];
    u8 reflectionPosition[ALPHABETSIZE];
    u8 rotateStatus;
    u8 breakPosition;
};


#endif // ROTOR_H
