#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/NetSerialization.h"
#include "AttackingPointInterface.h"
#include "DamageInstance.h"
#include "ECaveLeechState.h"
#include "EnemyPawn.h"
#include "CaveLeech.generated.h"

class AActor;
class UGrabberComponent;
class UHealthComponent;
class UHealthComponentBase;
class UPawnAffliction;
class USceneComponent;
class USkeletalMeshComponent;
UCLASS(Abstract, Blueprintable, NoExport)
class ACaveLeech : public AEnemyPawn, public IAttackingPointInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDamageInstance BiteDamage;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float StateTime;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_State, meta=(AllowPrivateAccess=true))
    ECaveLeechState State;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    FVector_NetQuantize TentacleLocation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UHealthComponent* HealthTarget;
 
    USkeletalMeshComponent* SkeletalMesh;
    UGrabberComponent* GrabberComponent;
    float BitesPerSecond;
    float MaxDistanceXY;
    float GrapDistance;
    float GrapDelay;
    float TentacleSpeed;
    float TentacleRetractSpeed;
    float RetractDuration;
    float TentaclePullSpeed;
    float TentacleDropPlayerSpeed;
    float TentacleDropGroundDistance;
    float MaxDropPlayerDuration;
    float HeadInterpSpeed;
    float TentacleAttachOffset;
    float BiteDistance;
    float RevivedGracePeriod;
    UPawnAffliction* CaveLeechSenseAffliction;
    FVector_NetQuantize TentacleVelocity;
    TWeakObjectPtr<AActor> Target;
    USceneComponent* TentacleHead;
    ACaveLeech(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void UnImmobilize();
    UFUNCTION()
    void OnRep_State();
    void Immobilize();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetTentacleTargetLocation() const;
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    FVector GetMouthLocation() const;
    AActor* GetCurrentTarget();
    void Died(UHealthComponentBase* HealthComponent);
    void Damaged(float amount);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnStateChanged(ECaveLeechState NewState);
    void BP_OnBite(UHealthComponent* TargetHealth);
    // Fix for true pure virtual functions not being implemented
};
