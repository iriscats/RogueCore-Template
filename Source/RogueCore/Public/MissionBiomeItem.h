#pragma once
#include "CoreMinimal.h"
#include "MissionBiomeItem.generated.h"

class UBiome;
USTRUCT(BlueprintType)
struct FMissionBiomeItem {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBiome* Biome;
    
    float Rarity;
    ROGUECORE_API FMissionBiomeItem();
};
