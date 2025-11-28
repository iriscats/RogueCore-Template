#pragma once
#include "CoreMinimal.h"
#include "DamageCondition.h"
#include "EPlasmaCarbineConditions.h"
#include "PlasmaCarbineDamageCondition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UPlasmaCarbineDamageCondition : public UDamageCondition {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPlasmaCarbineConditions WeaponCondition;
    
    int32 Condition;
    UPlasmaCarbineDamageCondition();
};
