#pragma once
#include "CoreMinimal.h"
#include "TXNegotiationSelectionOption.h"
#include "TXWeaponNegotiationEndEvent_Negotiation_Selection.generated.h"

USTRUCT(BlueprintType)
struct FTXWeaponNegotiationEndEvent_Negotiation_Selection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTXNegotiationSelectionOption> Options;
    
    FString requested;
    FString Selected;
    bool was_select_contested;
    ROGUECORE_API FTXWeaponNegotiationEndEvent_Negotiation_Selection();
};
