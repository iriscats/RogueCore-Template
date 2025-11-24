#pragma once
#include "CoreMinimal.h"
#include "AnimatedItem.h"
#include "JetPackItem.generated.h"

class UCurveFloat;
class UPlayerMovementComponent;
UCLASS(Abstract, Blueprintable, NoExport)
class AJetPackItem : public AAnimatedItem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))

    UPlayerMovementComponent* CharacterMovement;

    AJetPackItem(const FObjectInitializer& ObjectInitializer);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float ActiveTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* VerticalAccelerationCurve;
    float VerticalAcceleration;
    float MaxVerticalSpeed;
    float MaxHorizontalSpeed;
    float MaxHorizontalDrift;
    float BurnDuration;
    float RechargeDuration;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Fuel, meta=(AllowPrivateAccess=true))
    float Fuel;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Active, meta=(AllowPrivateAccess=true))
    bool Active;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPlayerMovementComponent* CharacterMovement;
    AJetPackItem(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Server_StopThruster_Implementation();
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Server_StartThruster_Implementation();
    UFUNCTION(BlueprintCallable)
    void OnRep_Fuel(float OldFuel);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRep_Active();
    void OnFuelChanged(float Value, float Delta);
};
