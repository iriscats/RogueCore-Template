#pragma once
#include "CoreMinimal.h"
#include "BXEUnlockAction.h"
#include "DamageModifierItem.h"
#include "BXEDamageUpgradeAction.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UBXEDamageUpgradeAction : public UBXEUnlockAction {
    GENERATED_BODY()
    

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDamageModifierItem Modifier;
    
    UBXEDamageUpgradeAction();
};
