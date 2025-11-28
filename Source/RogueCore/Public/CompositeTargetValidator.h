#pragma once
#include "CoreMinimal.h"
#include "TargetValidator.h"
#include "CompositeTargetValidator.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UCompositeTargetValidator : public UTargetValidator {
    GENERATED_BODY()
    

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UTargetValidator*> TargetValidators;

    UCompositeTargetValidator();

};
