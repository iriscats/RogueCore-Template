#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Curves/CurveFloat.h"
#include "SpecialAttackComponent.h"
#include "SplineHookAttack.generated.h"

class AActor;
class UAnimMontage;
class UDamageComponent;
class UHitReactionComponent;
class UPointLightComponent;
class USkeletalMeshComponent;
class USoundCue;
class USplineMeshComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class USplineHookAttack : public USpecialAttackComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USplineMeshComponent* Spline;
    
    USkeletalMeshComponent* HeadMesh;
    USkeletalMeshComponent* TailMesh;
    UHitReactionComponent* HitReacts;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve MovementCurve;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> SyncedTarget;
    FName TailSocket;
    FName HeadSocket;
    UPointLightComponent* GrabLight;
    USoundCue* GrabbedIndicationSound;
    UAnimMontage* HeadAnimation;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDamageComponent* Damage;
    float ForwardPlacement;
    float DesiredLaunchAngle;
    float MaxAngledForce;
    float AdjustmentStartDistance;
    float AttackDuration;
    float MaxAngle;
    float AttackOnProgress;
    float AttackDelay;
    float LeadMultiplier;
    float AquireLocationTime;
    bool ShowGrabArea;
    bool Lead;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Using, meta=(AllowPrivateAccess=true))
    bool Using;
    USplineHookAttack(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SetTailLight(UPointLightComponent* Light);
    UFUNCTION()
    void OnRep_Using();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetTargetLocation() const;
    FVector GetTargetDirection() const;
    bool GetHasAquiredTarget() const;
};
