#include "TargetDummyPawn.h"

ATargetDummyPawn::ATargetDummyPawn(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void ATargetDummyPawn::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const {
    TagContainer = GameplayTags;
}

bool ATargetDummyPawn::HasMatchingGameplayTag(FGameplayTag TagToCheck) const {
    return GameplayTags.HasTag(TagToCheck);
}

bool ATargetDummyPawn::HasAnyMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const {
    return GameplayTags.HasAny(TagContainer);
}

bool ATargetDummyPawn::HasAllMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const {
    return GameplayTags.HasAll(TagContainer);
}


