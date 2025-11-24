#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ElementEffects.generated.h"

UCLASS(Blueprintable)
class ROGUECORE_API UElementEffects : public UObject {
    GENERATED_BODY()
public:
    UElementEffects(const FObjectInitializer& ObjectInitializer);
};