#include "LevelGenerationDebris.h"

ULevelGenerationDebris::ULevelGenerationDebris(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Debris = NULL;
    this->Influencer = NULL;
    this->Range = 1000.00f;
    this->SelfActivate = false;
}


