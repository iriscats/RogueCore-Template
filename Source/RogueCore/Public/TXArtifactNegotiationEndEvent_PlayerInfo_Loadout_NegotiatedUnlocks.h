#pragma once
#include "CoreMinimal.h"
#include "TXArtifactNegotiationEndEvent_PlayerInfo_Loadout_NegotiatedUnlocks.generated.h"

USTRUCT(BlueprintType)
struct FTXArtifactNegotiationEndEvent_PlayerInfo_Loadout_NegotiatedUnlocks {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    int32 Rarity;
    ROGUECORE_API FTXArtifactNegotiationEndEvent_PlayerInfo_Loadout_NegotiatedUnlocks();
};
