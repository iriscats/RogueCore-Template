#pragma once
#include "CoreMinimal.h"
#include "Mutator.h"
#include "NoOxygenMutator.generated.h"

class UOxygenComponent;
class UStatusEffect;
UCLASS(Blueprintable, EditInlineNew)
class UNoOxygenMutator : public UMutator {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OxygenReplenishmentRate;
    
    TSoftClassPtr<UOxygenComponent> OxygenComponent;
    TSoftClassPtr<UStatusEffect> ReplenishOxygenEffect;
    UNoOxygenMutator();
};
