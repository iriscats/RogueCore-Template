#include "TagHealthCondition.h"

UTagHealthCondition::UTagHealthCondition() {
    this->HealthIsMoreThan = 100.00f;
    this->UsePercent = false;
    this->CheckHealthOn = ETagEffectTarget::EOwner;
}


