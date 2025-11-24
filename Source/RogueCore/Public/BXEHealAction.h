#pragma once
#include "CoreMinimal.h"
#include "BXEUnlockAction.h"
#include "BXEHealAction.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UBXEHealAction : public UBXEUnlockAction {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HealPercent;
    
    UBXEHealAction();
};
