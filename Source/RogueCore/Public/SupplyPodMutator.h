#pragma once
#include "CoreMinimal.h"
#include "Mutator.h"
#include "SupplyPodMutator.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class USupplyPodMutator : public UMutator {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section


public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CostModifier;
    
    USupplyPodMutator();
};
