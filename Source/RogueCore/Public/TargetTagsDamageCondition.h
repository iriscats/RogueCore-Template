#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "DamageCondition.h"
#include "TargetTagsDamageCondition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UTargetTagsDamageCondition : public UDamageCondition {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagQuery TagQuery;
    
    UTargetTagsDamageCondition();
};
