#pragma once
#include "CoreMinimal.h"
#include "SpawnRarityItem.generated.h"

USTRUCT(BlueprintType)
struct FSpawnRarityItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Duration;
    
    float Rarity;
    ROGUECORE_API FSpawnRarityItem();
};
