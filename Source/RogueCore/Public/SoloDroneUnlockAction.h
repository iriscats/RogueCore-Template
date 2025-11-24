#pragma once
#include "CoreMinimal.h"
#include "BXEUnlockAction.h"
#include "EBoscoUpgrades.h"
#include "SoloDroneUnlockAction.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class USoloDroneUnlockAction : public UBXEUnlockAction {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EBoscoUpgrades Type;
    
    float amount;
    USoloDroneUnlockAction();
};
