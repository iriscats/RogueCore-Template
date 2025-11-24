#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Mutator.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ROGUECORE_API UMutator : public UDataAsset {
    GENERATED_BODY()
public:
    UMutator();
};
