#include "BXEDeferredSpawnLogicUnlock.h"
#include "Templates/SubclassOf.h"

UBXEDeferredSpawnLogicUnlock::UBXEDeferredSpawnLogicUnlock(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

AActor* UBXEDeferredSpawnLogicUnlock::SetupSpawn(TSubclassOf<AActor> Spawnable, APawn* Instigator) {
    return NULL;
}

void UBXEDeferredSpawnLogicUnlock::FinishSpawning(AActor* Actor, const FTransform& Transform) {
}


