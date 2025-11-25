#pragma once
#include "CoreMinimal.h"
#include "AmmoDrivenWeapon.h"
#include "BeltDrivenWeapon.generated.h"

class UAudioComponent;
class UCurveFloat;
class USoundCue;
UCLASS(Abstract, Blueprintable)
class ABeltDrivenWeapon : public AAmmoDrivenWeapon {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section


public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAudioComponent* BarrelAudio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* BarrelSound;
    float BarrelFadeIn;
    float BarrelFadeOut;
    UCurveFloat* BarrelPitchCurve;
    float BarrelSpinUpTime;
    float BarrelSpinDownTime;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float CurrentSpinRate;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    bool Simulate_SpinBarrel;
    ABeltDrivenWeapon(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_StopBarrel();
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_StartBarrel();
};
