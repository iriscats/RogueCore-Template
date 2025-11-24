#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "JetBootsSettings.generated.h"

UCLASS(Blueprintable)
class UJetBootsSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float JetForce;
    
    float AirControlSpeed;
    float MaxAirSpeed;
    float MaxJetFuel;
    float JetFuelCost;
    float JetFuelRechargeRate;
    float JetFuelRechargeDelay;
    float OutOfFuelRechargeDelay;
    UJetBootsSettings();
};
