#include "umkehrwalze.h"

Umkehrwalze::Umkehrwalze()
{

}

void Umkehrwalze::initialize(u8 * ukwConfiguration){
    memcpy(ukwPosition, ukwConfiguration, ALPHABETSIZE);
}


u8 Umkehrwalze::passSignal(u8 input){
    return ukwPosition[input];
}
