#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CopyBoneVisibilityCompleted.h"
#include "MicroMissileLauncherAnimInstance.generated.h"

class AMicroMissileLauncher;
class UAnimMontage;
UCLASS(Blueprintable, NonTransient)
class UMicroMissileLauncherAnimInstance : public UAnimInstance, public ICopyBoneVisibilityCompleted {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AMicroMissileLauncher* Weapon;
    
    UMicroMissileLauncherAnimInstance();
    UFUNCTION(BlueprintCallable)
    void OnMontageEndedInternal(UAnimMontage* Montage, bool interrupted);
    // Fix for true pure virtual functions not being implemented
    UFUNCTION()
    void CopyBoneVisibilityCompleted(int32 BoneIndex) override PURE_VIRTUAL(CopyBoneVisibilityCompleted,);
};
