#include "BXEHangingLootObjective.h"
#include "Templates/SubclassOf.h"

UBXEHangingLootObjective::UBXEHangingLootObjective(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

AActor* UBXEHangingLootObjective::SpawnSuspender(UObject* WorldContextObject, const TSubclassOf<AActor> suspenderClass, const FVector& EndPoint, const FVector& endPointNormal, const FVector offsetToLineStart, UDebrisPositioning* debrisPosition, int32 maxTries, UCurveFloat* CostCurve, const TArray<FVector>& LocationsToAvoid) {
    return NULL;
}


