#pragma once
#include "CoreMinimal.h"
#include "TXNegotiationEndEvent_Character.generated.h"

USTRUCT(BlueprintType)
struct FTXNegotiationEndEvent_Character {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 current_health;
    
    int32 max_health;
    int32 shield_capacity;
    ROGUECORE_API FTXNegotiationEndEvent_Character();
};
