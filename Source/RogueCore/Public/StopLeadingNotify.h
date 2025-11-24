#pragma once
#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Animation/AnimNotifies/AnimNotify.h"
#include "StopLeadingNotify.generated.h"

UCLASS(Blueprintable, CollapseCategories)
class UStopLeadingNotify : public UAnimNotify {
    GENERATED_BODY()
public:
    UStopLeadingNotify();
};
