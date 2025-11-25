#pragma once
#include "CoreMinimal.h"
#include "DebrisLocationFinder.h"
#include "MeteorSpawnedDelegateDelegate.h"
#include "RandRange.h"
#include "PlagueMeteorSpawner.generated.h"

class APlagueMeteor;
UCLASS(Abstract, Blueprintable)
class APlagueMeteorSpawner : public ADebrisLocationFinder {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMeteorSpawnedDelegate OnSpawnedMeteor;
    
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<APlagueMeteor> MeteorActorClass;
    FRandRange EscortSpawnFromMuleRange;
    float EscortSpawnFromImportantRange;
    float EscortMinimum2DSpawnDistFromPath;
    float EscortMinimumZSpawnDistFromPath;
    float DropLocationHeightOffset;
    float ImportantLocationRange;
    UClass* MeteorActorClassLoaded;
    APlagueMeteorSpawner(const FObjectInitializer& ObjectInitializer);
};
