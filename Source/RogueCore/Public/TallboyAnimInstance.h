#pragma once
#include "CoreMinimal.h"
#include "SpiderAnimInstance.h"
#include "TallboyAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class ROGUECORE_API UTallboyAnimInstance : public USpiderAnimInstance {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected sectio

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsAiming;
    
    UTallboyAnimInstance();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetUpperBodyBlend() const;
};
