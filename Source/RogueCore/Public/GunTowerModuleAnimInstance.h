#pragma once
#include "CoreMinimal.h"

#include "Animation/AnimInstance.h"
#include "GunTowerModuleAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UGunTowerModuleAnimInstance : public UAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRotator CurrentModuleRotation;
    
    FRotator CurrentLookAtRotation;
    bool IsModuleActive;
    bool AreWeakpointsExposed;
    UGunTowerModuleAnimInstance();
};
