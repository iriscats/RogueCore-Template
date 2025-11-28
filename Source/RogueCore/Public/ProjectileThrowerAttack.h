#pragma once
#include "CoreMinimal.h"

#include "ProjectileAttackComponent.h"
#include "Templates/SubclassOf.h"
#include "ProjectileThrowerAttack.generated.h"

class UAnimInstance;
class UAnimMontage;
class USkeletalMesh;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UProjectileThrowerAttack : public UProjectileAttackComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

public:
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USkeletalMesh* ThrowerMesh;
    
    TSubclassOf<UAnimInstance> ThrowerAnimInstance;
    TArray<UAnimMontage*> ThrowerMontages;
    FName ThrowerAttachPoint;
    bool RotateToTarget;
    FRotator ThrowerRotation;
    FVector ThrowerOffset;
    UProjectileThrowerAttack(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void OnThrowerMontageEnded(UAnimMontage* Montage, bool bInterrupted);
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_ShowThrowerAnimation();
};
