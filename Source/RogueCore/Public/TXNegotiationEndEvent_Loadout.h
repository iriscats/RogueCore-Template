#pragma once
#include "CoreMinimal.h"
#include "TXNegotiationEndEvent_Loadout_Items.h"
#include "TXNegotiationEndEvent_Loadout.generated.h"

USTRUCT(BlueprintType)
struct FTXNegotiationEndEvent_Loadout {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTXNegotiationEndEvent_Loadout_Items> Items;
    
    TArray<FString> personal_unlocks;
    TArray<FString> negotiated_unlocks;
    FString artifact_name;
    ROGUECORE_API FTXNegotiationEndEvent_Loadout();
};
