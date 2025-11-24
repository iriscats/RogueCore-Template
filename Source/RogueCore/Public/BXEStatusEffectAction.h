#pragma once
#include "CoreMinimal.h"
#include "BXEUnlockAction.h"
#include "Templates/SubclassOf.h"
#include "BXEStatusEffectAction.generated.h"

class UStatusEffect;
UCLASS(Blueprintable, EditInlineNew)
class UBXEStatusEffectAction : public UBXEUnlockAction {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> StatusEffect;
    
    UBXEStatusEffectAction();
};
