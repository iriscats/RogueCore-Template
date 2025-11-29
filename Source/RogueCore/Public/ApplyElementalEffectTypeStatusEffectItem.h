#pragma once
#include "CoreMinimal.h"
#include "StatusEffectItem.h"
#include "ApplyElementalEffectTypeStatusEffectItem.generated.h"

class AItem;
class UElementType;
UCLASS(Blueprintable, EditInlineNew)
class UApplyElementalEffectTypeStatusEffectItem : public UStatusEffectItem {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UElementType* ElementalType;
    
    UApplyElementalEffectTypeStatusEffectItem();
 
    UFUNCTION(BlueprintCallable)
    void OnItemUnequipped(AItem* Item);
    void OnItemEquipped(AItem* Item);
};
