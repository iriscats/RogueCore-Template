#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Rotator_NoQuantize.generated.h"

USTRUCT(BlueprintType)
struct FRotator_NoQuantize : public FRotator {
    GENERATED_BODY()
public:
    ROGUECORE_API FRotator_NoQuantize();
};
