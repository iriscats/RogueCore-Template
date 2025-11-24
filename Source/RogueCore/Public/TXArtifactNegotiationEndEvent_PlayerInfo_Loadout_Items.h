#pragma once
#include "CoreMinimal.h"
#include "TXArtifactNegotiationEndEvent_PlayerInfo_Loadout_Items.generated.h"

USTRUCT(BlueprintType)
struct FTXArtifactNegotiationEndEvent_PlayerInfo_Loadout_Items {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Type;
    
    FString Name;
    FString Slot;
    int32 Rarity;
    FString max_ammo;
    FString current_ammo;
    TArray<FString> upgrades;
    ROGUECORE_API FTXArtifactNegotiationEndEvent_PlayerInfo_Loadout_Items();
};
