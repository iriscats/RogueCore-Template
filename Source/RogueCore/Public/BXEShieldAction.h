#pragma once
#include "CoreMinimal.h"
#include "BXEUnlockAction.h"
#include "BXEShieldAction.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UBXEShieldAction : public UBXEUnlockAction {
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CapacityAddition;
    
    float RegenFactorAddition;
    float DegredationRateAddition;
    UBXEShieldAction();
};
