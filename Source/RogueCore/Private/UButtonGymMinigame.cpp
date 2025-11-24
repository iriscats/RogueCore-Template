#include "UButtonGymMinigame.h"
#include "EGymGamemode.h"

UUButtonGymMinigame::UUButtonGymMinigame(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->GymMode = EGymGamemode::Button;
}


