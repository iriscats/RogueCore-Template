#pragma once
#include "CoreMinimal.h"
#include "RandRange.h"
#include "StatusEffectItem.h"
#include "PlayerArmorDamageStatusEffectItem.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UPlayerArmorDamageStatusEffectItem : public UStatusEffectItem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRandRange ChangeAmount;
    
    UPlayerArmorDamageStatusEffectItem();
};
