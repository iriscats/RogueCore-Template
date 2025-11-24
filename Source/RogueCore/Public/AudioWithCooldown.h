#pragma once
#include "CoreMinimal.h"
#include "AudioWithCooldown.generated.h"

class USoundCue;
USTRUCT(BlueprintType)
struct FAudioWithCooldown {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected sectio

public:
    ROGUECORE_API FAudioWithCooldown();
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* Audio;

    float CoolDown;
};
