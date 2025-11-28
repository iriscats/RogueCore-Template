#pragma once
#include "CoreMinimal.h"

#include "Curves/CurveFloat.h"
#include "EnemyPawn.h"
#include "FacilityTurret.generated.h"

class AActor;
class USceneComponent;
class USkeletalMeshComponent;
class USoundCue;
UCLASS(Blueprintable)
class AFacilityTurret : public AEnemyPawn {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    USkeletalMeshComponent* mesh;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IndicatorActivationDelay;
    bool FinishAttackIgnoreLoS;
    bool InvulnerableOnInactive;
    float FoldOutTime;
    USoundCue* EngagedAudio;
    float Offset;
    float AimAcceleration;
    FRuntimeFloatCurve AimSpeedCurve;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    AActor* CurrentTarget;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_TurretEngaged, meta=(AllowPrivateAccess=true))
    bool TurretEngaged;
    bool AlwaysActive;
    AFacilityTurret(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void TurnOffMesh();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetIsAttacking(bool IsAttacking);
    UFUNCTION()
    void OnRep_TurretEngaged();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnProjectileSpawned();
    void OnEngagedChanged(bool engaged);
    void OnAttack();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FRotator GetLookingDirection() const;
};
