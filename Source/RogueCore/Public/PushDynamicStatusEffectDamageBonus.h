#pragma once
#include "CoreMinimal.h"
#include "DamageBonusBase.h"
#include "Templates/SubclassOf.h"
#include "PushDynamicStatusEffectDamageBonus.generated.h"

class UStatusEffect;
UCLASS(Blueprintable, DefaultToInstanced, EditInlineNew)
class UPushDynamicStatusEffectDamageBonus : public UDamageBonusBase {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> BaseSTE;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UStatusEffect* StatusEffect;
    float Chance;
    UPushDynamicStatusEffectDamageBonus();
};
