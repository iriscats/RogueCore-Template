#pragma once
#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Animation/AnimNotifies/AnimNotify_PlaySound.h"
#include "FSDAnimNotify_PlayAttackSound.generated.h"

class USoundAttenuation;
UCLASS(Blueprintable, CollapseCategories)
class UFSDAnimNotify_PlayAttackSound : public UAnimNotify_PlaySound {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName IsTargetLocalPlayerParameter;
    
    USoundAttenuation* LocalPlayerAttenuationOverride;
    UFSDAnimNotify_PlayAttackSound();
};
