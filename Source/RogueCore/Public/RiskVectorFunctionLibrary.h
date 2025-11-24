#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RiskVectorFunctionLibrary.generated.h"

class URiskVector;
UCLASS(Blueprintable)
class URiskVectorFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    URiskVectorFunctionLibrary();
    UFUNCTION(BlueprintCallable)
    static TArray<URiskVector*> SortRiskVectors(const TArray<URiskVector*>& InRiskVectors);
    
};
