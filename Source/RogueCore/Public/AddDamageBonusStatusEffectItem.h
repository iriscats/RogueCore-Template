#pragma once
#include "CoreMinimal.h"
#include "EDamageBonusApplicationType.h"
#include "EDamageUpgrade.h"
#include "EDamagebonusMode.h"
#include "StatusEffectItem.h"
#include "Templates/SubclassOf.h"
#include "AddDamageBonusStatusEffectItem.generated.h"

class AActor;
class UDamageBonusBase;
UCLASS(Blueprintable, EditInlineNew)
class UAddDamageBonusStatusEffectItem : public UStatusEffectItem {
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<AActor>> OnlyApplyToActorTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDamageBonusBase* DamageBonus;
    float Value;
    EDamagebonusMode Mode;
    EDamageUpgrade BonusType;
    EDamageBonusApplicationType ApplicationType;
    UAddDamageBonusStatusEffectItem();
};
