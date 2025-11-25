#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CoreInfuserAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UCoreInfuserAnimInstance : public UAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool PoweredUp;
    
    bool IsOpen;
    bool IsRewardSelected;
    UCoreInfuserAnimInstance();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRewardSelected();
};
