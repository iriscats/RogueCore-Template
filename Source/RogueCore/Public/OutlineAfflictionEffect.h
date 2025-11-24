#pragma once
#include "CoreMinimal.h"
#include "AfflictionEffect.h"
#include "EOutline.h"
#include "OutlineAfflictionEffect.generated.h"

UCLASS(Blueprintable)
class UOutlineAfflictionEffect : public UAfflictionEffect {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOutline Outline;
    
    UOutlineAfflictionEffect();
};
