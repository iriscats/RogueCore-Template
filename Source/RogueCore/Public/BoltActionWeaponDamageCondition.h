#pragma once
#include "CoreMinimal.h"
#include "DamageCondition.h"
#include "EBoltActionWeaponConditions.h"
#include "BoltActionWeaponDamageCondition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UBoltActionWeaponDamageCondition : public UDamageCondition {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EBoltActionWeaponConditions WeaponCondition;
    
    UBoltActionWeaponDamageCondition();
};
