#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "BoscoAnimNotifyDelegateDelegate.h"
#include "EDroneAIState.h"
#include "BoscoAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UBoscoAnimInstance : public UAnimInstance {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBoscoAnimNotifyDelegate OnWeaponsReady;
    
    FBoscoAnimNotifyDelegate OnWeaponsNotReady;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float DigAnimPlayRate;
    EDroneAIState CurrentState;
    bool IsReadyToMine;
    bool IsMining;
    bool IsFiring;
    bool IsReviving;
    bool IsCarryingGem;
    UBoscoAnimInstance();
};
