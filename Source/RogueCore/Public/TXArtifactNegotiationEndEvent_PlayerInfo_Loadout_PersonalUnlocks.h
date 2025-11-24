#pragma once
#include "CoreMinimal.h"
#include "TXArtifactNegotiationEndEvent_PlayerInfo_Loadout_PersonalUnlocks.generated.h"

USTRUCT(BlueprintType)
struct FTXArtifactNegotiationEndEvent_PlayerInfo_Loadout_PersonalUnlocks {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    int32 amount;
    ROGUECORE_API FTXArtifactNegotiationEndEvent_PlayerInfo_Loadout_PersonalUnlocks();
};
