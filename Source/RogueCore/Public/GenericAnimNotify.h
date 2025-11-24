#pragma once
#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Animation/AnimNotifies/AnimNotify.h"
#include "GenericAnimNotify.generated.h"

UCLASS(Blueprintable, CollapseCategories)
class UGenericAnimNotify : public UAnimNotify {
    GENERATED_BODY()
public:
    UGenericAnimNotify();
};
