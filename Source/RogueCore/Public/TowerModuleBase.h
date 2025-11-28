#pragma once
#include "CoreMinimal.h"

#include "EGuntowerModuleState.h"
#include "EventParticipant.h"
#include "FSDPawn.h"
#include "TowerModuleBase.generated.h"

class UEnemyHealthComponent;
class UFXSystemAsset;
class USceneComponent;
class USkeletalMesh;
class USkeletalMeshComponent;
class USoundCue;
class UStaticMeshComponent;
UCLASS(Blueprintable)
class ATowerModuleBase : public AFSDPawn, public IEventParticipant {
    GENERATED_BODY()
    


public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    USkeletalMeshComponent* ModuleMesh;
    TArray<UStaticMeshComponent*> ArmorPlates;
    UEnemyHealthComponent* Health;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    FRotator ModuleRotation;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USkeletalMesh* DestroyedMesh;
    USoundCue* deathSound;
    UFXSystemAsset* deathParticles;
    float ArmorLaunchPower;
    float HideArmorTime;
    float ModuleRotationSpeed;
    bool ConstantRotation;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_State, meta=(AllowPrivateAccess=true))
    EGuntowerModuleState State;
    ATowerModuleBase(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetState(EGuntowerModuleState NewState);
    UFUNCTION(BlueprintCallable)
    void OnRep_State(EGuntowerModuleState prevState);
    void HideArmorPlates();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void DoAttack();
    // Fix for true pure virtual functions not being implemented
};
