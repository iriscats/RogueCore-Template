#include "AccessLibrary.h"

UAccessLibrary::UAccessLibrary() {
}

void UAccessLibrary::RemoveTemporaryAccessConditionToActor(AActor* Actor, UAccessCondition* Condition) {
}

void UAccessLibrary::RemovePermanentAccessConditionFromLocalPlayer(UObject* WorldContext, UAccessCondition* Condition) {
}

bool UAccessLibrary::DoesActorHaveAccessCondition(const AActor* Actor, const UAccessCondition* Condition) {
    return false;
}

void UAccessLibrary::AddTemporaryAccessConditionToActor(AActor* Actor, UAccessCondition* Condition) {
}

void UAccessLibrary::AddPermanentAccessConditionToLocalPlayer(UObject* WorldContext, UAccessCondition* Condition) {
}


