#pragma once
#include "CoreMinimal.h"
#include "AfflictionEffect.h"
#include "StaggeredAfflictionEffect.generated.h"

UCLASS(Blueprintable)
class UStaggeredAfflictionEffect : public UAfflictionEffect {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StaggerStrength;
    
    UStaggeredAfflictionEffect();
};
