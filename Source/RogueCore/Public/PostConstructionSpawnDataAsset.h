#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PostConstructionSpawnInfo.h"
#include "PostConstructionSpawnDataAsset.generated.h"

UCLASS(Blueprintable)
class UPostConstructionSpawnDataAsset : public UDataAsset {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPostConstructionSpawnInfo> SpawnInfo;
    
    UPostConstructionSpawnDataAsset();
};
