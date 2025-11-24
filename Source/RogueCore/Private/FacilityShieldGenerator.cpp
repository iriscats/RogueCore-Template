#include "FacilityShieldGenerator.h"

AFacilityShieldGenerator::AFacilityShieldGenerator(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void AFacilityShieldGenerator::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const {
    TagContainer = GameplayTags;
}


