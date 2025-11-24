#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BXEUnlockAction.h"
#include "BXELogicAction.generated.h"

class UBXELogicUnlockComponent;
UCLASS(Blueprintable, EditInlineNew)
class UBXELogicAction : public UBXEUnlockAction {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UBXELogicUnlockComponent> LogicUnlockClass;
    
    float amount;
    bool UseHardClamp;
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval HardClampInterval;
    UBXELogicAction();
};
