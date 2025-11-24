#pragma once
#include "CoreMinimal.h"
#include "AbilityItemAnimInstance.h"
#include "AbilityDroneControllerAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UAbilityDroneControllerAnimInstance : public UAbilityItemAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Walking;
    
    bool Running;
    bool InAir;
    bool BirdOnGlove;
    UAbilityDroneControllerAnimInstance();
};
