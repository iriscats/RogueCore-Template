#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "GameplayTagContainer.h"
#include "RandRange.h"
#include "BTDecorator_SetTagRandomCooldown.generated.h"

UCLASS(Blueprintable)
class UBTDecorator_SetTagRandomCooldown : public UBTDecorator {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag CooldownTag;
    
    FRandRange CooldownDuration;
    bool bAddToExistingDuration;
    bool TriggerOnActivation;
    UBTDecorator_SetTagRandomCooldown();
};
