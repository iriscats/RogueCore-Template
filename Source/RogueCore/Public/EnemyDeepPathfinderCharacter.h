#pragma once
#include "CoreMinimal.h"
#include "DeepPathfinderCharacter.h"
#include "NetMontageAble.h"
#include "QueuedMontage.h"
#include "EnemyDeepPathfinderCharacter.generated.h"

class UAnimInstance;
class UAnimMontage;
class UEnemyHealthComponent;
class UMaterialInterface;
class UMeshComponent;
class USkeletalMeshComponent;
UCLASS(Blueprintable, NoExport)
class AEnemyDeepPathfinderCharacter : public ADeepPathfinderCharacter, public INetMontageAble {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEnemyHealthComponent* HealthComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_QueuedMontage, meta=(AllowPrivateAccess=true))
    FQueuedMontage QueuedMontage;

protected:
    AEnemyDeepPathfinderCharacter(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void SwitchToDynamicBaseShader(UMaterialInterface* baseShader, UMeshComponent* MeshComponent) const;
    UFUNCTION(BlueprintCallable)
    void OnRep_QueuedMontage();
    // Fix for true pure virtual functions not being implemented
    float QueueMontage(UAnimMontage* Montage) override PURE_VIRTUAL(QueueMontage, return 0.0f;);
    USkeletalMeshComponent* GetSkeletalMesh() const override PURE_VIRTUAL(GetSkeletalMesh, return NULL;);
    UAnimInstance* GetAnimInstance() const override PURE_VIRTUAL(GetAnimInstance, return NULL;);
};
