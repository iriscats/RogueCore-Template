#include "MeterGymMinigame.h"
#include "EGymGamemode.h"

UMeterGymMinigame::UMeterGymMinigame(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->GymMode = EGymGamemode::Meter;
}


