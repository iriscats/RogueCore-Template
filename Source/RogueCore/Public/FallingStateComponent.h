#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/NetSerialization.h"
#include "CharacterStateComponent.h"
#include "InputCompatible.h"
#include "Templates/SubclassOf.h"
#include "FallingStateComponent.generated.h"

class UCameraShakeBase;
class UDamageClass;
class UDialogDataAsset;
class UFSDPhysicalMaterial;
class USoundCue;
class UStatusEffect;
class UUseAnimationSetting;
UCLASS(Blueprintable, MinimalAPI, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UFallingStateComponent : public UCharacterStateComponent, public IInputCompatible {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDamageClass* FallingDamageClass;
    
    float LightLandingBufferSize;
    float HeavyLandingBufferSize;
    USoundCue* LightLandingSound;
    USoundCue* HeavyLandingSound;
    TSubclassOf<UStatusEffect> HeavyLandingSTE;
    TSubclassOf<UCameraShakeBase> LightLandingShake;
    TSubclassOf<UCameraShakeBase> HeavyLandingShake;
    float FallDamageStartVelocity;
    float FallDamageModifier;
    float AutoClimbMinDelay;
    float AutoClimbLookForwardDistance;
    float MaxClimbHeight;
    float MinClimbHeight;
    float CapsuleCheckZOffset;
    float MinInputDotProduct;
    float JumpZVelocity;
    bool DebugAutoClimb;
    UDialogDataAsset* FallingShout;
    float ShoutAfterDistance;
    UUseAnimationSetting* ClimbUseSettings;
    float HoverBootAirFriction;
    float HoverBootAirControl;
    float HoverBootGravityScale;
    UDialogDataAsset* ShoutHoverBootsBegin;
    float HoverBootActivateDuration;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_HoverBootsActive, meta=(AllowPrivateAccess=true))
    bool bHoverBootsActive;
    float HoverBootMaxDuration;
    FVector2D JumpBootsVelocityWindow;
    float JumpBootsZVelocity;
    bool JumpBootsActive;
    UFallingStateComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowJumpBootsActivation();
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_TakeFallDamage(float amount);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetJumpPressed(bool Pressed);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetHoverBootsPressed(bool IsPressed);
    UFUNCTION(BlueprintCallable, Server, Unreliable)
    void Server_SetFallVelocity(float Velocity);
    UFUNCTION(BlueprintCallable, Server, Unreliable)
    void Server_ClimbLedge(bool shouldPlayAnimation);
    UFUNCTION(BlueprintCallable, Server, Unreliable)
    void Server_ActivateJumpBoots();
    void ReceiveHoverBootsTick(float DeltaSeconds);
    void ReceiveHoverBootsActiveChanged(bool IsActive);
    UFUNCTION(BlueprintCallable)
    void OnRep_HoverBootsActive();
    void JumpReleased();
    void JumpPressed();
    void HoverBootsReleased();
    void HoverBootsPressed();
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_ShowJumpBootsActivation();
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_ShowFallImpact(UFSDPhysicalMaterial* PhysMat, const FVector_NetQuantize& Location);
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_ShowClimbLedge();
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_PlayLightImpact();
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_PlayHeavyImpact();
};
