#pragma once
#include "CoreMinimal.h"
#include "MultiHitscanWeapon.h"
#include "SawedOffShotgun.generated.h"

class UDamageAsset;
class UDamageComponent;
UCLASS(Blueprintable)
class ASawedOffShotgun : public AMultiHitscanWeapon {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDamageAsset* ShockwaveDamage;
    
    float FearFactorOnFire;
    float FearFactorOnFireRadius;
    bool ShotgunJumpEnabled;
    float ShotgunJumpForce;
    bool ShockwaveEnabled;
    float ShockWaveDistance;
    ASawedOffShotgun(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetShockWaveDamageComponent(UDamageComponent* Component);
};
