#include "ChangeElementCondition.h"

UChangeElementCondition::UChangeElementCondition() {
    this->ChangeThreshold = 0.00f;
    this->CompareToAbsolute = false;
    this->MultiplyWithResistance = true;
    this->IgnoreTriggerFromDecay = true;
    this->AlsoCheckTransferElement = true;
}


