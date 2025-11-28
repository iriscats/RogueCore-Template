#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PostConstructionSpawnInfo.h"
#include "PostConstructionSpawnDataAsset.generated.h"

UCLASS(Blueprintable)
class UPostConstructionSpawnDataAsset : public UDataAsset {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPostConstructionSpawnInfo> SpawnInfo;
    
    UPostConstructionSpawnDataAsset();
};
