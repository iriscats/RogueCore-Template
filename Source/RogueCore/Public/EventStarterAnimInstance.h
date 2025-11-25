#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "EventStarterAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UEventStarterAnimInstance : public UAnimInstance {
    GENERATED_BODY()

 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float UseProgress;

    bool IsOpenForUse;

    bool IsBooted;

    bool IsEventActive;

public:
    UEventStarterAnimInstance();
};
