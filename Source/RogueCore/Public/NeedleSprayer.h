#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"

#include "WeaponFireOwner.h"
#include "NeedleSprayer.generated.h"

class APlayerCharacter;
class UAnimMontage;
class UFSDAudioComponent;
class UHitscanComponent;
class UNiagaraComponent;
class UPointLightComponent;
class USceneComponent;
class USkeletalMeshComponent;
UCLASS(Blueprintable, NoExport)
class ANeedleSprayer : public AActor, public IWeaponFireOwner {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    USkeletalMeshComponent* SKMesh;
    UHitscanComponent* FireComponent;
    UHitscanComponent* OnSpawnedEffectComponent;
    UPointLightComponent* MuzzleFlashLight;
    UNiagaraComponent* MuzzleFlashParticleSys;
    UNiagaraComponent* ImpactParticleComponent;
    USceneComponent* ShotOriginPivot;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UHitscanComponent* HitscanComponent;
    UFSDAudioComponent* SoundEnd;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* ReloadAnimation;
    int32 MaxRotations;
    int32 LinesPerRotation;
    FVector2D ShotAngleFromTop;
    float DeployDelay;
    float Lifetime;
    float TimeBetweenRotations;
    float RearmTime;
    float AvoidCloseOffset;
    float ShotOriginOffset;
    int32 MaxRearms;
    bool PlayAnimationOnBeginPlay;
    bool PlayAnimationOnReload;
    bool DrawDebugLines;
    float DebugLinesDuration;
    ANeedleSprayer(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSpinningChanged(bool isSpinning);
    UFUNCTION(BlueprintCallable)
    void OnHit(const FHitResult& Result, bool IsPenetrating);
    // Fix for true pure virtual functions not being implemented
    APlayerCharacter* GetPlayerCharacter() const override PURE_VIRTUAL(GetPlayerCharacter, return NULL;);
    FQuat GetMuzzleQuat() const override PURE_VIRTUAL(GetMuzzleQuat, return FQuat{};);
    FVector GetMuzzleLocation() const override PURE_VIRTUAL(GetMuzzleLocation, return FVector{};);
    bool GetIsLocallyControlled() const override PURE_VIRTUAL(GetIsLocallyControlled, return false;);
    bool GetIsFirstPerson() const override PURE_VIRTUAL(GetIsFirstPerson, return false;);
};
