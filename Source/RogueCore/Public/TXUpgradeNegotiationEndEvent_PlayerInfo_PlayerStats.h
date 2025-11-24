#pragma once
#include "CoreMinimal.h"
#include "TXUpgradeNegotiationEndEvent_PlayerInfo_PlayerStats.generated.h"

USTRUCT(BlueprintType)
struct FTXUpgradeNegotiationEndEvent_PlayerInfo_PlayerStats {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    int32 amount;
    ROGUECORE_API FTXUpgradeNegotiationEndEvent_PlayerInfo_PlayerStats();
};
