#pragma once
#include "CoreMinimal.h"
#include "Mutator.h"
#include "VeinMutator.generated.h"

class UVeinResourceData;
UCLASS(Blueprintable, EditInlineNew)
class ROGUECORE_API UVeinMutator : public UMutator {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected sectio

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UVeinResourceData* VeinResource;
    
    float Modifier;
    UVeinMutator();
};
