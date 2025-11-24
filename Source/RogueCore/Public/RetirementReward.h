#pragma once
#include "CoreMinimal.h"
#include "UnlockReward.h"
#include "RetirementReward.generated.h"

class UPlayerCharacterID;
UCLASS(Blueprintable, EditInlineNew)
class URetirementReward : public UUnlockReward {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPlayerCharacterID* characterID;
    
    URetirementReward();
};
