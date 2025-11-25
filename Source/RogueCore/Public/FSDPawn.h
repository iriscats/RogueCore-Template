#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Pawn.h"
#include "GameplayTagContainer.h"
#include "GameplayTagAssetInterface.h"
#include "BoolDelegateDelegate.h"
#include "EPawnAttitude.h"
#include "ElementState.h"
#include "PawnMaterialState.h"
#include "ProjectileSpawner.h"
#include "Targetable.h"
#include "FSDPawn.generated.h"

class AActor;
class AFSDAIController;
class UElementComponent;
class UElementType;
class UEnemyDescriptor;
class UHealthComponentBase;
class UMaterialInterface;
class UPawnStatsComponent;
class UPrimitiveComponent;
class UStatusEffectsComponent;
UCLASS(Abstract, Blueprintable, NoExport)
class AFSDPawn : public APawn, public IGameplayTagAssetInterface, public ITargetable, public IProjectileSpawner {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBoolDelegate OnFrozenEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStatusEffectsComponent* StatusEffects;
    UElementComponent* element;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer GameplayTags;
    UEnemyDescriptor* SpawnedFromDescriptor;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsFrozen, meta=(AllowPrivateAccess=true))
    bool IsFrozen;
    bool CanFlee;
    float MaxColdSlowdown;
    float MaxElectricSlowdown;
    bool FleeInsteadOfBackingOff;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool IsFleeing;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPawnStatsComponent* PawnStatsInstance;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_MaterialState, meta=(AllowPrivateAccess=true))
    FPawnMaterialState MaterialState;
    TArray<UMaterialInterface*> OriginalMaterials;
    AFSDPawn(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void UnFreeze();
    void StopFleeing();
    void StartFleeing(const FVector& fromLocation);
    void SetOverrideMaterial(UMaterialInterface* InOverrideMaterial);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetOriginalMaterials();
    void SetAlerted(bool isAlerted);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintImplementableEvent)
    void Receive_Alerted();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnUnFrozen();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStoppedFleeing();
    void OnStartedFleeing();
    UFUNCTION()
    void OnRep_MaterialState(FPawnMaterialState PrevMaterialState);
    UFUNCTION()
    void OnRep_IsFrozen();
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, BlueprintImplementableEvent)
    void OnFrozen(AActor* Source);
    void OnFrozen_Implementation(AActor* Source);
    void OnFirstHostileDamageTaken();
    void OnEnemyScaled(float NewScale);
    void OnElectricChanged(UElementType* ElementType, const FElementState& ElementState);
    void OnDeath(UHealthComponentBase* HealthComponent);
    void OnColdChanged(UElementType* ElementType, const FElementState& ElementState);
    void OnArmorShattered(const FVector& Location);
    void OnAlerted();
    void MakeRagdollMesh(UPrimitiveComponent* mesh);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintPure)
    bool GetIsAlerted() const;
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UHealthComponentBase* GetHealthComponent() const;
    AFSDAIController* GetFSDAIController() const;
    EPawnAttitude GetAttitude() const;
    void Freeze(AActor* Source);
    void ExplodePawn();
    void BackOffFromLocation(const FVector& fromLocation);
    // Fix for true pure virtual functions not being implemented
    bool HasMatchingGameplayTag(FGameplayTag TagToCheck) const override PURE_VIRTUAL(HasMatchingGameplayTag, return false;);
    bool HasAnyMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const override PURE_VIRTUAL(HasAnyMatchingGameplayTags, return false;);
    bool HasAllMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const override PURE_VIRTUAL(HasAllMatchingGameplayTags, return false;);
    void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override PURE_VIRTUAL(GetOwnedGameplayTags, ;);
    FGameplayTagContainer BP_GetOwnedGameplayTags() const override PURE_VIRTUAL(BP_GetOwnedGameplayTags, return FGameplayTagContainer{};);
};
