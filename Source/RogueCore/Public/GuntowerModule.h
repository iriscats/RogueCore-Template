#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EventParticipant.h"
#include "FSDPawn.h"
#include "GuntowerModule.generated.h"

class AActor;
class AGuntowerEvent;
class AGuntowerModule;
class UAnimSequenceBase;
class UFXSystemAsset;
class UGunTowerHealthComponent;
class USkeletalMeshComponent;
class USoundCue;
class UStaticMeshComponent;
UCLASS(Blueprintable, NoExport)
class AGuntowerModule : public AFSDPawn, public IEventParticipant {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* ExposeWeakpointSound;
    
    USoundCue* deathSound;
    UFXSystemAsset* deathParticles;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> WeakpointActors;
    FName BodyBone;
    FName TopConnectionPointName;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    FRotator CurrentTurretRotation;
    UAnimSequenceBase* IntroductionAnimation;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* ArmorPiece1;
    UStaticMeshComponent* ArmorPiece2;
    UStaticMeshComponent* ArmorPiece3;
    USkeletalMeshComponent* ModuleMesh;
    UGunTowerHealthComponent* GuntowerModuleHealth;
    AGuntowerEvent* OwningEvent;
    AGuntowerModule* ChildModule;
    float WeakpointsExposedTime;
    float WeakpointsExposedTimeSolo;
    float HideArmorTime;
    float ArmorShootoutDelay;
    float ArmorLaunchPower;
    int32 ModuleID;
    bool IsPassiveModule;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsModuleActive, meta=(AllowPrivateAccess=true))
    bool ModuleIsActive;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_AreWeakpointExposed, meta=(AllowPrivateAccess=true))
    bool AreWeakpointsExposed;
    bool AreWeaponsExposed;
    bool ConstantRotation;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsArmorOff, meta=(AllowPrivateAccess=true))
    bool IsArmorOff;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Exploded, meta=(AllowPrivateAccess=true))
    bool Exploded;
    AGuntowerModule(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void ShootOutArmor();
    void SetModuleActive();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTearArmor();
    UFUNCTION()
    void OnRep_IsModuleActive();
    UFUNCTION()
    void OnRep_IsArmorOff();
    UFUNCTION()
    void OnRep_Exploded();
    UFUNCTION()
    void OnRep_AreWeakpointExposed();
    void OnActivationChanged(bool IsActivated);
    void Introduce();
    void HideWeakpoints();
    void HideArmor();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetModuleID() const;
    void DoExplosion();
    void DeactivateTowerModule();
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_PlayIntroductionAnim();
    void ActivateTowerModule();
    // Fix for true pure virtual functions not being implemented
};
