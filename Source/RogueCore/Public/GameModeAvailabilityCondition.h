#pragma once
#include "CoreMinimal.h"
#include "BXEUnlockConditionBase.h"
#include "EGameModeAvailability.h"
#include "GameModeAvailabilityCondition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UGameModeAvailabilityCondition : public UBXEUnlockConditionBase {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameModeAvailability GameModeAvailability;
    
    UGameModeAvailabilityCondition();
};
