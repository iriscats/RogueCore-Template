#pragma once
#include "CoreMinimal.h"
#include "AttackEffect.h"
#include "NoiseCarveAttackEffect.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UNoiseCarveAttackEffect : public UAttackEffect {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExpensiveNoise;
    
    float CarveDiameterCM;
    float CarveNoiseCM;
    float CarveBurnThicknessCM;
    float CarverOffset;
    FName Socket;
    UNoiseCarveAttackEffect();
};
