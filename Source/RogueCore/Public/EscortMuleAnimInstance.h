#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "EscortMuleAnimInstance.generated.h"

class UHealthComponent;
UCLASS(Blueprintable, NonTransient)
class UEscortMuleAnimInstance : public UAnimInstance {
    GENERATED_BODY()

public:
    UEscortMuleAnimInstance();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTookDamage(UHealthComponent* Health);

protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool LeftCannistersVisible;

    bool RightCannistersVisible;

    bool IsEngineRunning;

    bool IsBeingRefueled;

    bool PlatformOut;
};
