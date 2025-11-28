#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"

#include "ECharacterCameraMode.h"
#include "ECharacterState.h"
#include "JetBootsActiveDelegate.h"
#include "JetBootsDelegateDelegate.h"
#include "JetBootsMovementComponent.generated.h"

class AActor;
class APlayerCharacter;
class UAudioComponent;
class UFXSystemAsset;
class UFXSystemComponent;
class UJetBootsSettings;
class UNiagaraComponent;
class UNiagaraSystem;
class UPrimitiveComponent;
class USkeletalMesh;
class USkeletalMeshComponent;
class USoundCue;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UJetBootsMovementComponent : public UActorComponent {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FJetBootsActive OnJetBootsActiveChanged;
    
 
    FJetBootsDelegate FuelUpdated;
    FJetBootsDelegate FuelUpdatedNonLocal;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UJetBootsSettings* Settings;
    TSoftObjectPtr<USoundCue> UseSound;
    TSoftObjectPtr<USoundCue> DeactivatedSound;
    TSoftObjectPtr<USoundCue> OverHeatSound;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAudioComponent* UseAudioComponent;
    UAudioComponent* OverHeatAudioComponent;
    UAudioComponent* DeactivatedAudioComponent;
    UAudioComponent* TP_UseAudioComponent;
    UAudioComponent* TP_OverHeatAudioComponent;
    UAudioComponent* TP_DeactivatedAudioComponent;
    TSoftObjectPtr<UNiagaraSystem> FootParticles;
    TSoftObjectPtr<UFXSystemAsset> FootParticlesFP;
    FName FootSocketNameLeft;
    FName FootSocketNameRight;
    USkeletalMesh* FootAttachMesh;
    USkeletalMeshComponent* LFootAttachMeshComponent;
    USkeletalMeshComponent* RFootAttachMeshComponent;
    UNiagaraComponent* LeftFootParticles;
    UNiagaraComponent* RightFootParticles;
    UFXSystemComponent* FPFootParticles;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APlayerCharacter* Character;
    float FromJumpDelay;
    float FromTerrainStartDelay;
    float OverHeatAtPercent;
    float AddPlayerAirVelocityToThrowFactor;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_CurrentJetFuel, meta=(AllowPrivateAccess=true))
    float CurrentJetFuel;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_IsUsing, meta=(AllowPrivateAccess=true))
    bool isUsing;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    bool isFromTakeOff;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_OverHeated, meta=(AllowPrivateAccess=true))
    bool overheated;
    UJetBootsMovementComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Server_SetOverheated(bool Current);
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Server_SetIsUsing(bool Current, bool Last, bool NewIsFromTakeOff);
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Server_SetCurrentJetFuel(float Current);
    UFUNCTION(BlueprintCallable)
    void RemoveJetBoots();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Receive_OnTakeOffLocal();
    void Receive_OnOverheatedChanged(bool NewOverheated);
    void Receive_OnDestroy();
    void Receive_OnCharacterSet(APlayerCharacter* Player);
    void Receive_OnActiveChangedServer(bool IsActive, bool fromTakeOff);
    void Receive_OnActiveChangedNonLocal(bool IsActive, bool fromTakeOff);
    void Receive_OnActiveChangedLocal(bool IsActive, bool fromTakeOff);
    void OnStateChanged(ECharacterState State);
    UFUNCTION()
    void OnRep_OverHeated(bool lastOverheated);
    UFUNCTION()
    void OnRep_IsUsing(bool lastUsing);
    UFUNCTION()
    void OnRep_CurrentJetFuel();
    void OnPlayerCharacterHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
    void OnJumpReleased();
    void OnJumpPressed();
    void OnCameraModeChanged(ECharacterCameraMode newCameraMode, ECharacterCameraMode OldCameraMode);
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void Client_SetIsUsing(bool NewIsUsing);
};
