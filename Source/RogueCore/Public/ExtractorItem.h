#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/NetSerialization.h"
#include "AnimatedItem.h"
#include "CharacterChangedDelegateDelegate.h"
#include "EExtractorState.h"
#include "FloatDelegateDelegate.h"
#include "Throwable.h"
#include "ExtractorItem.generated.h"

class AResourceChunk;
class UAnimMontage;
class UBoxComponent;
class UDialogDataAsset;
class UFSDAudioComponent;
class UFXSystemAsset;
class UFirstPersonParticleSystemComponent;
class UForceFeedbackEffect;
class UNiagaraComponent;
class UParticleSystemComponent;
class UPointLightComponent;
class UResourceData;
class USkeletalMeshComponent;
class USoundCue;
UCLASS(Blueprintable, NoExport)
class ROGUECORE_API AExtractorItem : public AAnimatedItem, public IThrowable {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatDelegate OnCurrentLoadChangedEvent;
    
    FCharacterChangedDelegate OnCharacterEquipChange;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* DroppedCollider;
    USkeletalMeshComponent* DroppedMesh;
    UFirstPersonParticleSystemComponent* FP_DrillParticles;
    UFSDAudioComponent* AudioComponent;
    UPointLightComponent* SurfaceLight;
    UParticleSystemComponent* MeltingParticles;
    UParticleSystemComponent* InvalidSurfaceParticles;
    UParticleSystemComponent* FPMuzzleParticles;
    UParticleSystemComponent* FPMuzzleInvalidParticles;
    UParticleSystemComponent* TPMuzzleParticles;
    UParticleSystemComponent* TPMuzzleInvalidParticles;
    UNiagaraComponent* MeltingParticlesNS;
    UNiagaraComponent* InvalidSurfaceParticlesNS;
    UNiagaraComponent* FPMuzzleParticlesNS;
    UNiagaraComponent* FPMuzzleInvalidParticlesNS;
    UNiagaraComponent* TPMuzzleParticlesNS;
    UNiagaraComponent* TPMuzzleInvalidParticlesNS;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* FPMineMontage;
    UAnimMontage* TPMineMontage;
    UAnimMontage* FPGunsling;
    UAnimMontage* TPGunsling;
    FName MiningSpeedAudioParamterName;
    UFXSystemAsset* DrillParticles;
    UForceFeedbackEffect* DrillRumble;
    float BlockParticlesScaleFP;
    float BlockParticlesScaleTP;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    EExtractorState State;
    float MovementPenalty;
    float CarverRayCastLength;
    float CarveTerrainDistanceCheck;
    float CurrentDrillSpeed;
    float DrillParticlesDuration;
    UResourceData* ExtractetMaterial;
    float TimeBeforeInvalidShout;
    UDialogDataAsset* InvalidSurfaceShout;
    UDialogDataAsset* ShoutFull;
    USoundCue* DigSound;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_SimulatingMining, meta=(AllowPrivateAccess=true))
    bool IsMining;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_IsGunslinging, meta=(AllowPrivateAccess=true))
    bool IsGunslinging;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    bool ReadyToExtract;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_CurrentLoad, meta=(AllowPrivateAccess=true))
    float CurrentLoad;

 
    UFXSystemAsset* VacuumEffect;
    UFXSystemAsset* ChunkSplatEffect;
    USoundCue* ChunkSplatSound;
    float MaxDifference;
    float MeltingTime;
    float ChunkMultiplier;
    float CollectChunkCooldown;
    float CrossfadeSpeed;
    float VacuumEffectOffset;
    float MaxCapacity;
    float PlayerCountBonus;
    FColor SurfaceLightInitialColor;
    FColor SurfaceLightEndColor;
    float SurfaceLightMinIntensity;
    float SurfaceLightMaxIntensity;
    AExtractorItem(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintImplementableEvent)
    void SetCanPickup(bool canPickup);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_StopMining();
    UFUNCTION(Server, Reliable)
    void Server_StartMining();
    UFUNCTION(Server, Reliable)
    void Server_SetReadyToExtract(bool IsReady);
    UFUNCTION(Server, Reliable)
    void Server_DigBlock(FVector_NetQuantize Start, FVector_NetQuantize End);
    UFUNCTION(Server, Reliable)
    void Server_CollectChunk(AResourceChunk* chunk);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void ResetCurrentLoad();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnValidSurfaceChanged(bool IsValid);
    void OnThrown(FVector Direction);
    void OnStopDrilling();
    void OnStartDrilling();
    UFUNCTION(BlueprintCallable)
    void OnRep_SimulatingMining();
    UFUNCTION()
    void OnRep_IsGunslinging();
    UFUNCTION()
    void OnRep_CurrentLoad();
    void OnCurrentLoadChanged(float Load);
    void OnChunkCooldownOver();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFull() const;
    UBoxComponent* GetRootCollider() const;
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_SimulateDigBlock(FVector_NetQuantize position, bool spawnParticles, int32 Material);
    UFUNCTION(NetMulticast, Unreliable)
    void All_ChunkSplat(AResourceChunk* chunk);
    void AddResource(float amount);
    // Fix for true pure virtual functions not being implemented
};
