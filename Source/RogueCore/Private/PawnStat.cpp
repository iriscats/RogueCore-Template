#include "PawnStat.h"

UPawnStat::UPawnStat() {
    this->DisplayText = FText::FromString(TEXT("Default__PawnStat"));
    this->StartingValue = 0.00f;
    this->PawnStatType = EPawnStatType::Multiplicative;
    this->ValueModificationType = EPawnStatType::Multiplicative;
}


