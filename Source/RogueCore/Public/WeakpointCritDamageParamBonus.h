#pragma once
#include "CoreMinimal.h"
#include "DamageParamBonus.h"
#include "WeakpointCritDamageParamBonus.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UWeakpointCritDamageParamBonus : public UDamageParamBonus {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AdditionalCritChance;
    
    UWeakpointCritDamageParamBonus();
};
