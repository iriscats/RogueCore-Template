#pragma once
#include "CoreMinimal.h"
#include "MultiHitscanWeapon.h"
#include "SawedOffShotgun.generated.h"

class UDamageAsset;
class UDamageComponent;
UCLASS(Blueprintable, NoExport)
class ASawedOffShotgun : public AMultiHitscanWeapon {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
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
