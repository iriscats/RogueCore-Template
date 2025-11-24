#pragma once
#include "CoreMinimal.h"
#include "TerrainPlacementActor.generated.h"

class AActor;
USTRUCT(BlueprintType)
struct FTerrainPlacementActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> ActorClass;
    
    int32 AmountOfActors;
    bool AddTerrainPlacementBlockers;
    ROGUECORE_API FTerrainPlacementActor();
};
