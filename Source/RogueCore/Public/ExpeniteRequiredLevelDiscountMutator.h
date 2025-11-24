#pragma once
#include "CoreMinimal.h"
#include "Mutator.h"
#include "ExpeniteRequiredLevelDiscountMutator.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UExpeniteRequiredLevelDiscountMutator : public UMutator {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExpeniteDiscount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 LevelAcquired;
    UExpeniteRequiredLevelDiscountMutator();
};
