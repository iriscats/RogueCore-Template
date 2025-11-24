#pragma once
#include "CoreMinimal.h"
#include "TagEffectBase.h"
#include "ReturnAmmoEffect.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UReturnAmmoEffect : public UTagEffectBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HealthConversionMultiplier;
    
    UReturnAmmoEffect();
};
