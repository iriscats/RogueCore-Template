#pragma once
#include "CoreMinimal.h"
#include "TXArtifactNegotiationEndEvent_PlayerInfo_Loadout_Items.h"
#include "TXArtifactNegotiationEndEvent_PlayerInfo_Loadout_NegotiatedUnlocks.h"
#include "TXArtifactNegotiationEndEvent_PlayerInfo_Loadout_PersonalUnlocks.h"
#include "TXArtifactNegotiationEndEvent_PlayerInfo_Loadout.generated.h"

USTRUCT(BlueprintType)
struct FTXArtifactNegotiationEndEvent_PlayerInfo_Loadout {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTXArtifactNegotiationEndEvent_PlayerInfo_Loadout_Items> Items;
    
    TArray<FTXArtifactNegotiationEndEvent_PlayerInfo_Loadout_PersonalUnlocks> personal_unlocks;
    TArray<FTXArtifactNegotiationEndEvent_PlayerInfo_Loadout_NegotiatedUnlocks> negotiated_unlocks;
    TArray<FString> artifacts;
    ROGUECORE_API FTXArtifactNegotiationEndEvent_PlayerInfo_Loadout();
};
