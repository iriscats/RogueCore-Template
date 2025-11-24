#include "BTService_FindAlly.h"

UBTService_FindAlly::UBTService_FindAlly() {
    this->MaxSameTypeSupportingActors = 0;
    this->Query = NULL;
    this->Sorting = NoSorting;
    this->MaxRange = 0.00f;
    this->MustBeAlive = true;
    this->UpdateTarget = false;
}


