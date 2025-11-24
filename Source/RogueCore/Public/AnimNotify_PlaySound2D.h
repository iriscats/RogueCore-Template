#pragma once
#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Animation/AnimNotifies/AnimNotify.h"
#include "AnimNotify_PlaySound2D.generated.h"

class USoundBase;
UCLASS(Blueprintable, CollapseCategories, MinimalAPI)
class UAnimNotify_PlaySound2D : public UAnimNotify {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* Sound;
    
    float VolumeMultiplier;
    float PitchMultiplier;
    UAnimNotify_PlaySound2D();
};
