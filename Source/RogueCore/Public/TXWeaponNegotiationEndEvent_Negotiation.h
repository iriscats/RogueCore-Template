#pragma once
#include "CoreMinimal.h"
#include "TXWeaponNegotiationEndEvent_Negotiation_Selection.h"
#include "TXWeaponNegotiationEndEvent_Negotiation.generated.h"

USTRUCT(BlueprintType)
struct FTXWeaponNegotiationEndEvent_Negotiation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString negotiation_pool;
    
    FTXWeaponNegotiationEndEvent_Negotiation_Selection Selection;
    ROGUECORE_API FTXWeaponNegotiationEndEvent_Negotiation();
};
