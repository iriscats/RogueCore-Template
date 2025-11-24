#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EImpulseDirectionSource.h"
#include "DamageImpulse.generated.h"

UCLASS(Blueprintable)
class UDamageImpulse : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ImpactForce;
    
    float UpwardForceScale;
    EImpulseDirectionSource ImpulseSource;
    bool ApplyImpulseToWholeBody;
    UDamageImpulse();
};
