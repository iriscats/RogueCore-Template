#pragma once
#include "CoreMinimal.h"
#include "DeathIntroSettings.generated.h"

USTRUCT(BlueprintType)
struct FDeathIntroSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FirstPersonDuration;
    
    float FadeToBlackDelay;
    float FadeToBlackDuration;
    float FadeFromBlackDelay;
    float FadeFromBlackDuration;
    float ZoomOutDuration;
    float ZoomOutStartDistance;
    ROGUECORE_API FDeathIntroSettings();
};
