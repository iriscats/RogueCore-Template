#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemUpgradeCondition.h"
#include "PlayerShieldsItemUpgradeCondition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UPlayerShieldsItemUpgradeCondition : public UItemUpgradeCondition {
    GENERATED_BODY()
    
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval ShieldPercentageRequired;
    
    UPlayerShieldsItemUpgradeCondition();
};
