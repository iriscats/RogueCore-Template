#pragma once
#include "CoreMinimal.h"
#include "TXUpgradeNegotiationEndEvent_PlayerInfo_Loadout_PersonalUnlocks.generated.h"

USTRUCT(BlueprintType)
struct FTXUpgradeNegotiationEndEvent_PlayerInfo_Loadout_PersonalUnlocks {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    int32 amount;
    ROGUECORE_API FTXUpgradeNegotiationEndEvent_PlayerInfo_Loadout_PersonalUnlocks();
};
