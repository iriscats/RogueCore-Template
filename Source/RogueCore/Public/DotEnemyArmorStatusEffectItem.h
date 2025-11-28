#pragma once
#include "CoreMinimal.h"
#include "RandRange.h"
#include "StatusEffectItem.h"
#include "DotEnemyArmorStatusEffectItem.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UDotEnemyArmorStatusEffectItem : public UStatusEffectItem {
    GENERATED_BODY()
    

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRandRange damageAmount;
    
    UDotEnemyArmorStatusEffectItem();
};
