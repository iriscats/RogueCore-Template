#pragma once
#include "CoreMinimal.h"
#include "TXPlayerData.generated.h"

USTRUCT(BlueprintType)
struct FTXPlayerData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 kills;
    
    int32 deaths;
    int32 revives;
    int32 mined;
    int32 damage_dealt;
    int32 damage_taken;
    ROGUECORE_API FTXPlayerData();
};
