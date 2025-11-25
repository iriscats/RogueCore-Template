#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GuntowerModule.h"
#include "WeaponFireOwner.h"
#include "HostileGuntowerModule.generated.h"

class APlayerCharacter;
class UEnemyComponent;
class UHealthComponentBase;
class UNiagaraComponent;
class UParticleSystemComponent;
class USkeletalMeshComponent;
UCLASS(Blueprintable, NoExport)
class AHostileGuntowerModule : public AGuntowerModule, public IWeaponFireOwner {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* DestroyedMesh;
    
    UParticleSystemComponent* DestroyedSmoke;
    UNiagaraComponent* DestroyedSmokeNS;

    UEnemyComponent* EnemyComponent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ModuleMaxHealth, meta=(AllowPrivateAccess=true))
    float ModuleMaxHealth;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    FRotator CurrentAimRotation;
    AHostileGuntowerModule(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnWeakpointDied(UHealthComponentBase* Health);
    UFUNCTION()
    void OnRep_ModuleMaxHealth();
    void OnModuleDied(UHealthComponentBase* Health);
    // Fix for true pure virtual functions not being implemented
    APlayerCharacter* GetPlayerCharacter() const override PURE_VIRTUAL(GetPlayerCharacter, return NULL;);
    FQuat GetMuzzleQuat() const override PURE_VIRTUAL(GetMuzzleQuat, return FQuat{};);
    FVector GetMuzzleLocation() const override PURE_VIRTUAL(GetMuzzleLocation, return FVector{};);
    bool GetIsLocallyControlled() const override PURE_VIRTUAL(GetIsLocallyControlled, return false;);
    bool GetIsFirstPerson() const override PURE_VIRTUAL(GetIsFirstPerson, return false;);
};
