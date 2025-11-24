#include "GymActivityProperties.h"

UGymActivityProperties::UGymActivityProperties() {
    this->AnimStart = NULL;
    this->AnimIdleUp = NULL;
    this->AnimIdleDown = NULL;
    this->AnimGoingUp = NULL;
    this->AnimGoingDown = NULL;
    this->AnimFailUp = NULL;
    this->AnimFailDown = NULL;
    this->AnimEnd = NULL;
    this->AnimAdditiveStruggleUp = NULL;
    this->AnimAdditiveStruggleDown = NULL;
    this->PointSound = NULL;
    this->SuccessSound = NULL;
    this->FailSound = NULL;
    this->CurrencyType = NULL;
    this->BaseDifficulty = EGymDifficulty::Normal;
    this->MaxDifficulty = EGymDifficulty::Karl;
    this->GymIcon = NULL;
    this->GymIconRAW = NULL;
    this->SingleMotion = false;
    this->AlternativeVersion = false;
    this->GymActivityStats = NULL;
}


