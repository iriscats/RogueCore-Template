#pragma once
#include "CoreMinimal.h"

#include "HostileTargetingGuntowerModule.h"
#include "LMGGuntoweModule.generated.h"

class UAudioComponent;
class UDamageComponent;
class UFXSystemAsset;
class UHitscanComponent;
class USceneComponent;
class USoundCue;
UCLASS(Blueprintable)
class ALMGGuntoweModule : public AHostileTargetingGuntowerModule {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHitscanComponent* HitScanComp;
    
    UDamageComponent* DamageComp;
    USceneComponent* AimAtWhenNoTarget;
    UAudioComponent* FireAudio;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFXSystemAsset* TracerEffect;
    UFXSystemAsset* MuzzleEffect;
    USoundCue* ShootTailSound;
    int32 BurstSize;
    float MaxAimOffset;
    float IdleAimRotationSpeed;
    float TimeBetweenShots;
    float TimeBetweenBursts;
    float AimSpeed;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsFiresoundPlaying, meta=(AllowPrivateAccess=true))
    bool IsFiresoundPlaying;
    ALMGGuntoweModule(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void ShowShot(const FVector& Location);
    UFUNCTION()
    void OnRep_IsFiresoundPlaying();
};
