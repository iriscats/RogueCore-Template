#pragma once
#include "CoreMinimal.h"
#include "ElementChangeArgs.generated.h"

class AActor;
USTRUCT(BlueprintType)
struct FElementChangeArgs {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* Source;
    
    bool IgnoreResistances;
    bool IgnoreEventTriggers;
    ROGUECORE_API FElementChangeArgs();
};
