#include "frontpanel.h"

FrontPanel::FrontPanel()
{

}

void FrontPanel::initialize(u8 * frontPanelConfiguration){
    memcpy(frontPanelPosition, frontPanelConfiguration, ALPHABETSIZE);
    populateReflections();
}

void FrontPanel::populateReflections(){
    for(u8 i = 0; i < ALPHABETSIZE; i++){
        reflectionPosition[frontPanelPosition[i]] = i;
    }
}

u8 FrontPanel::passSignal(u8 input){
    return frontPanelPosition[input];
}

u8 FrontPanel::reverseSignal(u8 input){
    return reflectionPosition[input];
}
