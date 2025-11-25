#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "GameFramework/Pawn.h"
#include "Templates/SubclassOf.h"
#include "PlayerCameraDrone.generated.h"

class AActor;
class ALaserPointerMarker;
class AVanityCharacter;
class UAnimationAsset;
class UPawnMovementComponent;
class UPrimitiveComponent;
UCLASS(Abstract, Blueprintable, NoExport)
class APlayerCameraDrone : public APawn {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section


public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPawnMovementComponent* Movement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MenuTab;
    bool SplineMeshIsVisible;
    float SplineSpeed;
    float MouseSensitivity;
    float CameraRoll;
    bool CameraDoesShake;
    bool IsFollowingPlayerRotation;
    FVector FollowPositionOffset;
    bool UseFreeRotation;
    bool UseDOF;
    TSubclassOf<AActor> VanitySpawnable;
    TSubclassOf<AActor> VanityWeaponSpawnable;
    TArray<TSoftObjectPtr<UAnimationAsset>> VanityCharacterAnimations;
    int32 SelectedVanityClassIndex;
    int32 SelectedVanityAnimation;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AVanityCharacter*> VanityCharacterInstances;
    TArray<AVanityCharacter*> StaticVanityCharacterInstances;
    TSubclassOf<ALaserPointerMarker> DroneMarker;
    ALaserPointerMarker* ActiveMarker;
    TSubclassOf<AActor> Flare;
    TArray<AActor*> FlareInstances;
    TSubclassOf<AActor> BounceFlare;
    TArray<AActor*> BounceFlareInstances;
    AActor* SplineInstance;
    TArray<AActor*> SplineMeshInstances;
    TSubclassOf<AActor> Spline;
    TSubclassOf<AActor> SplineMesh;
    AActor* PlayerFollowed;
    AActor* WeaponTrackActor;
    APlayerCameraDrone(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    bool ToggleSplineMeshVisibility();
    void SetRotationalPivotToPlayer();
    void SetFlareLightSettings(float Intensity, float Range, float Color);
    bool SetCameraShakeAmount(float Value);
    void SetBounceFlareLightSettings(float Intensity, float Range, float Color);
    void SaveLightConfig();
    void ResetFollowVariables();
    void ResetAllLights();
    void OnFlareHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
    void LoadLightConfig();
    FVector GetFlareLightSettings();
    FVector GetBounceFlareLightSettings();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void CreateHUD();
    void ClearFocusPoint();
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void All_BeginCountdown();
};
