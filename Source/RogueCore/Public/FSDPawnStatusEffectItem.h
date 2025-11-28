#pragma once
#include "CoreMinimal.h"
#include "StatusEffectItem.h"
#include "FSDPawnStatusEffectItem.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UFSDPawnStatusEffectItem : public UStatusEffectItem {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StaggerDurationMultiplier;
    
    float AttackSpeedModifier;
    UFSDPawnStatusEffectItem();
};
