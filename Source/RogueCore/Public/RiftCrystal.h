#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"

#include "Curves/CurveFloat.h"
#include "Engine/NetSerialization.h"
#include "GameplayTagContainer.h"
// // #include "GameplayTags/GameplayTagAssetInterface.h" // UE5中已移除 // UE5中已移除
#include "BossFightInterface.h"
#include "DamageData.h"
#include "ERiftCrystalState.h"
#include "RiftBeam.h"
#include "RiftCrystalDelegateDelegate.h"
#include "Templates/SubclassOf.h"
#include "RiftCrystal.generated.h"

class AGem;
class UAudioComponent;
class UCapsuleComponent;
class UCurveFloat;
class UCurveVector;
class UDamageComponent;
class UDamageTag;
class UDebrisPositioning;
class UEnemyComponent;
class UEnemyHealthComponent;
class UHealthComponent;
class UHealthComponentBase;
class UMeshCarverComponent;
class UNiagaraComponent;
class UNiagaraSystem;
class UPathfinderCollisionComponent;
class UPhysicalMaterial;
class UPointLightComponent;
class UPrimitiveComponent;
class URiftSpawnerComponent;
class URotatingSceneComponent;
class USceneComponent;
class USkeletalMeshComponent;
class USoundCue;
class USpawnActorWithDebrisPosComponent;
class UTerrainDetectComponent;
UCLASS(Blueprintable, NoExport)
class ARiftCrystal : public AActor, public IGameplayTagAssetInterface, public IBossFightInterface {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_State, meta=(AllowPrivateAccess=true))

    TEnumAsByte<ERiftCrystalState> State;

    ARiftCrystal(const FObjectInitializer& ObjectInitializer);



public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    USceneComponent* FlightRoot;
    URotatingSceneComponent* Bobber;
    URotatingSceneComponent* Rotator;
    USkeletalMeshComponent* CrystalMesh;
    UCapsuleComponent* WeakpointCollision;
    UPointLightComponent* Light;
    UPointLightComponent* LargeLight;
    UCapsuleComponent* KnockBackCapsule;
    UMeshCarverComponent* SpaceCarver;
    TArray<UTerrainDetectComponent*> TerrainDetectors;
    UNiagaraComponent* EnergyParticles;
    UNiagaraComponent* PillarParticles;
    UAudioComponent* RockIdleSound;
    UAudioComponent* CrystalIdleSound;
    UNiagaraComponent* InvulnerableParticles;
    UPathfinderCollisionComponent* EscortBlocker;
    USpawnActorWithDebrisPosComponent* DebrisSpawner;
    UEnemyHealthComponent* Health;
    URiftSpawnerComponent* RiftSpawner;
    UEnemyComponent* Enemy;
    UDamageComponent* KnockBackDamge;
    UDamageComponent* EndExplosionDamage;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRiftCrystalDelegate OnStateChanged;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BeamTargetParamName;
    FGameplayTagContainer GameplayTags;
    FRotator SpawnedRotation;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FRiftBeam> Beams;
    TArray<AActor*> KnockbackTargets;
    UCurveVector* DeathRattle;
    FRuntimeFloatCurve KnockBackCurve;
    TSubclassOf<AGem> DroppedActorClass;
    TSubclassOf<AActor> ExtractionPodClass;
    UDebrisPositioning* ExtractionPodPositioning;
    UCurveFloat* ExtractionPodCostCurve;
    UPhysicalMaterial* InvulnerableOverride;
    UPhysicalMaterial* WeakPointMaterial;
    USoundCue* InitialBreakFreeSound;
    USoundCue* BreakFreeSound;
    USoundCue* ActivatedWarningSound;
    USoundCue* BeamShootSound;
    USoundCue* BeamImpactSound;
    USoundCue* EmbeddedSound;
    USoundCue* PushBackSound;
    UNiagaraSystem* PushBackEffect;
    UNiagaraSystem* BeamEffect;
    UNiagaraSystem* BeamImpactEffect;
    float DeathDisplayTime;
    float SafetyDistance;
    float TargetFlightHeight;
    float KnockBackInterval;
    float MaxFallSpeed;
    float FallAcceleration;
    float CheckPathsInterval;
    float ReinforcementCooldown;
    float BossHealthBarDelay;
    bool InitialCarvingDone;
    bool RotateBeamComponents;
    FRuntimeFloatCurve FlightCurve;
    FRuntimeFloatCurve FallCurve;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_State, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ERiftCrystalState> State;
    ARiftCrystal(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void StopWave();
    UFUNCTION(BlueprintCallable)
    void StopRumble();
    void StartWave();
    void StartRumble();
    void SpawnReinforcements();
    void SpawnExtractionPod(FVector locaiton);
    void ShowHeathBar();
    void ShowCallingEffects() const;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetState(TEnumAsByte<ERiftCrystalState> NewState);
    void ReplaceCrystal(FTransform SpawnTransform);
    void Receive_ExitedState(TEnumAsByte<ERiftCrystalState> NewState);
    void Receive_EnteredState(TEnumAsByte<ERiftCrystalState> NewState);
    void OnTerrainPointRemoved(USceneComponent* Point);
    void OnRiftSpawned(AActor* rift);
    UFUNCTION()
    void OnRep_State(TEnumAsByte<ERiftCrystalState> oldState);
    void OnNewHealthSegment(int32 currentSegment, int32 prevSegment);
    void OnExitedKnockbackZone(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    void OnEnteredKnockbackZone(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    void OnDeath(UHealthComponent* HealthComponent, float damageAmount, const FDamageData& DamageData, const TArray<UDamageTag*>& DamageTags);
    void OnDamaged(float Damage, const FDamageData& DamageData, bool anyHealthLost, UHealthComponentBase* HealthComponent);
    void OnAllRiftsOpened();
    void EnableTerrainDetection();
    void DisableTerrainDetection();
    void DestroyPillar();
    void CarvePillar(bool showEffects);
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_ShowRiftSpawnEffects(FVector_NetQuantize riftLocation);
    void All_AddKnockBack(FVector_NetQuantize Direction, float Force);
    // Fix for true pure virtual functions not being implemented
    bool HasMatchingGameplayTag(FGameplayTag TagToCheck) const override PURE_VIRTUAL(HasMatchingGameplayTag, return false;);
    bool HasAnyMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const override PURE_VIRTUAL(HasAnyMatchingGameplayTags, return false;);
    bool HasAllMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const override PURE_VIRTUAL(HasAllMatchingGameplayTags, return false;);
    FGameplayTagContainer BP_GetOwnedGameplayTags() const override PURE_VIRTUAL(BP_GetOwnedGameplayTags, return FGameplayTagContainer{};);
};
