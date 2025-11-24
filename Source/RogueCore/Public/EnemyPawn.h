#pragma once
#include "CoreMinimal.h"
#include "FSDPawn.h"
#include "NetMontageAble.h"
#include "QueuedMontage.h"
#include "EnemyPawn.generated.h"

class UAnimInstance;
class UAnimMontage;
class UEnemyComponent;
class UEnemyHealthComponent;
class UEnemyPawnAfflictionComponent;
class UMaterialInterface;
class UMeshComponent;
class UPawnStatsComponent;
class USkeletalMeshComponent;
UCLASS(Abstract, Blueprintable, NoExport)
class AEnemyPawn : public AFSDPawn, public INetMontageAble {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEnemyHealthComponent* Health;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CenterMassSocketName;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_QueuedMontage, meta=(AllowPrivateAccess=true))
    FQueuedMontage QueuedMontage;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInterface*> CachedMaterials;

protected:
    UPawnStatsComponent* Stats;
    UEnemyPawnAfflictionComponent* Affliction;
    UEnemyComponent* Enemy;
    AEnemyPawn(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UMeshComponent* Receive_GetMeshComponent() const;
    UFUNCTION(BlueprintCallable)
    void OnRep_QueuedMontage();
    USkeletalMeshComponent* GetMesh() const;
    // Fix for true pure virtual functions not being implemented
    float QueueMontage(UAnimMontage* Montage) override PURE_VIRTUAL(QueueMontage, return 0.0f;);
    USkeletalMeshComponent* GetSkeletalMesh() const override PURE_VIRTUAL(GetSkeletalMesh, return NULL;);
    UAnimInstance* GetAnimInstance() const override PURE_VIRTUAL(GetAnimInstance, return NULL;);
};
