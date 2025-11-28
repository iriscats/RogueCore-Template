#pragma once
#include "CoreMinimal.h"
#include "DamageBonusBase.h"
#include "WeakpointDamageBonus.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UWeakpointDamageBonus : public UDamageBonusBase {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AdditionalWeakpointDamage;
    
    UWeakpointDamageBonus();
};
