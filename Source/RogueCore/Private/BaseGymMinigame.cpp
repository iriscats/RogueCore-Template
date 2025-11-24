#include "BaseGymMinigame.h"

UBaseGymMinigame::UBaseGymMinigame(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Properties = NULL;
    this->GymComponent = NULL;
    this->MinigameWidget = NULL;
    this->GymMode = EGymGamemode::None;
}


