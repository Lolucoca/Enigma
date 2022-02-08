#ifndef FRONTPANEL_H
#define FRONTPANEL_H

#include "rotor.h"

class FrontPanel
{
public:
    FrontPanel();
    void initialize(u8 * frontPanelConfiguration);
    u8 passSignal(u8 input);
    u8 reverseSignal(u8 input);
private:
    void populateReflections();
    u8 frontPanelPosition[ALPHABETSIZE];
    u8 reflectionPosition[ALPHABETSIZE];
};

#endif // FRONTPANEL_H
