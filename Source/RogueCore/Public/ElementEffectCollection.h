#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ElementEffectCollection.generated.h"

UCLASS(Blueprintable)
class ROGUECORE_API UElementEffectCollection : public UObject {
    GENERATED_BODY()
public:
    UElementEffectCollection(const FObjectInitializer& ObjectInitializer);
};