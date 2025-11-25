#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Animation/AnimInstance.h"
#include "AnimNotifyDelegateDelegate.h"
#include "EndEffector.h"
#include "IsAttackingChangedDelegateDelegate.h"
#include "NameDelegateDelegate.h"
#include "EnemyAnimInstance.generated.h"

class UHealthComponentBase;
class UIKComponent;
class UPoseCorrectionComponent;
class USkeletalMeshComponent;
UCLASS(Blueprintable, NonTransient)
class UEnemyAnimInstance : public UAnimInstance {
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimNotifyDelegate OnRangedAttackNotify;

    FAnimNotifyDelegate OnGenericNotify;
    FNameDelegate OnMeleeAttackNotify;
    FAnimNotifyDelegate OnStopLeadingNotify;
    FIsAttackingChangedDelegate OnIsAttackingChanged;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool IsAttacking;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEndEffector> EndEffectors;

    FVector BodyPoseCorrectionLocation;
    FRotator BodyPoseCorrectionRotation;
    float IKBlend;
    bool IKEnabled;
    bool IsAlive;
    float RandomStartPosition;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UHealthComponentBase* HealthComponent;

    UIKComponent* IKComponent;

    UPoseCorrectionComponent* PoseCorrectionComponent;

    UEnemyAnimInstance(const FObjectInitializer& ObjectInitializer);
    UEnemyAnimInstance();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSlotPlayingAnyAnimation(FName SlotNodeName) const;

    bool IsNotAttacking() const;

    bool IsDead() const;

    USkeletalMeshComponent* GetSkeletalMesh() const;

    FEndEffector GetEndEffector1();

    FEndEffector GetEndEffector0();
};
