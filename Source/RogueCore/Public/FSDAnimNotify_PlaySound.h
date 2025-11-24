#pragma once
#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Animation/AnimNotifies/AnimNotify_PlaySound.h"
#include "FSDAnimNotify_PlaySound.generated.h"

UCLASS(Blueprintable, CollapseCategories)
class UFSDAnimNotify_PlaySound : public UAnimNotify_PlaySound {
    GENERATED_BODY()
public:
    UFSDAnimNotify_PlaySound();
};
