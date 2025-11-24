#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AttackBaseComponent.h"
#include "EProjectileAttackRotationType.h"
#include "ProjectileAttackDelegateDelegate.h"
#include "ProjetileSpawnedDelegateDelegate.h"
#include "ProjectileAttackBaseComponent.generated.h"

class AActor;
class UAnimMontage;
class UProjectileAttack;
class UTargetValidator;
UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UProjectileAttackBaseComponent : public UAttackBaseComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UProjectileAttack*> Projectiles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAnimMontage*> Montages;
    FName SocketName;
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EProjectileAttackRotationType RotationHandling;
    UTargetValidator* FinalValidationCheck;
    bool ProjectilesIgnoreEachOther;
    FVector OriginOffsetOverride;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FProjectileAttackDelegate OnAttackStartedEvent;
    FProjectileAttackDelegate OnProjectileFiredEvent;
    FProjectileAttackDelegate OnAttackEndedEvent;
    FProjetileSpawnedDelegate OnProjectileSpawnedEvent;
    UProjectileAttackBaseComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    bool TriggerMontage(AActor* Target);
    void SpawnProjectile();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UAnimMontage* SelectMontage() const;
    void OnPerformAttack();
    void OnMontageEnded(UAnimMontage* Montage, bool interrupted);
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void MulticastProjectileFired();
    void CancelMontage();
    void AddProjectile(UProjectileAttack* Projectile);
};
