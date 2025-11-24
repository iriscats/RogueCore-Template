#include "RunGymMinigame.h"
#include "EGymGamemode.h"

URunGymMinigame::URunGymMinigame(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->GymMode = EGymGamemode::Run;
}


