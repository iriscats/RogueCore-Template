#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GeneratedRunProperties.h"
#include "RunCreationParameters.h"
#include "RunGenerationLibrary.generated.h"

UCLASS(Blueprintable)
class ROGUECORE_API URunGenerationLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    URunGenerationLibrary();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FGeneratedRunProperties ComputeRunProperties(const FRunCreationParameters& Parameters);
    
};
