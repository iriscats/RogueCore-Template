#pragma once
#include "CoreMinimal.h"
#include "BXEUnlockAction.h"
#include "BXEAmmoUpgradeAction.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UBXEAmmoUpgradeAction : public UBXEUnlockAction {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
x
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AmmoModifier;
    
    UBXEAmmoUpgradeAction();
};
