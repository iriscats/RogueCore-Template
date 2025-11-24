#pragma once
#include "CoreMinimal.h"
#include "DamageAttackComponent.h"
#include "EAttackOrigin.h"
#include "MeleeAttackDelegateDelegate.h"
#include "MeleeAttackComponent.generated.h"

class UAnimMontage;
class UAttackEffect;
class UTargetValidator;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UMeleeAttackComponent : public UDamageAttackComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAnimMontage*> Montages;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTargetValidator* HitValidator;
    FName FromSocket;
    bool CenterOnTarget;
    EAttackOrigin AttackOrigin;
    TArray<UAttackEffect*> AttackEffects;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMeleeAttackDelegate OnAttackStartedEvent;
    FMeleeAttackDelegate OnDamageAppliedEvent;
    FMeleeAttackDelegate OnAttackEndedEvent;
    bool RequireLineOfSight;
    UMeleeAttackComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UAnimMontage* SelectMontage() const;
    UFUNCTION(BlueprintCallable)
    void OnPerformAttack(FName Name);
    void OnMontageEnded(UAnimMontage* Montage, bool interrupted);
};
