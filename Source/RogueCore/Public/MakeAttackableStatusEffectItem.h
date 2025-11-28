#pragma once
#include "CoreMinimal.h"
#include "StatusEffectItem.h"
#include "Templates/SubclassOf.h"
#include "MakeAttackableStatusEffectItem.generated.h"

class UAttackerPositioningComponent;
UCLASS(Blueprintable, EditInlineNew)
class UMakeAttackableStatusEffectItem : public UStatusEffectItem {
    GENERATED_BODY()
    
public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AttackCostModifier;
    
    TSubclassOf<UAttackerPositioningComponent> ComponentClass;
    UMakeAttackableStatusEffectItem();
};
