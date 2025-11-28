#pragma once
#include "CoreMinimal.h"
#include "AudioWithCooldown.generated.h"

class USoundCue;
USTRUCT(BlueprintType)
struct FAudioWithCooldown {
    GENERATED_BODY()
    

public:
    ROGUECORE_API FAudioWithCooldown();
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* Audio;

    float CoolDown;
};
