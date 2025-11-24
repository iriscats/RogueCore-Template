#pragma once
#include "CoreMinimal.h"
#include "BXEUnlockAction.h"
#include "BXEPawnStatAction.generated.h"

class UPawnStat;
UCLASS(Blueprintable, EditInlineNew)
class UBXEPawnStatAction : public UBXEUnlockAction {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPawnStat* PawnStat;
    
    float Value;
    bool IsModifierPercent;
    UBXEPawnStatAction();
};
