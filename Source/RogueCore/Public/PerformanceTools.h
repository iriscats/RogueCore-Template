#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PerformanceTools.generated.h"

class AActor;
UCLASS(Blueprintable)
class UPerformanceTools : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UPerformanceTools();
    UFUNCTION(BlueprintCallable)
    static void SetStaticMobilityOnComponents(AActor* act);
    
    static void SetMaxDrawDistancesOnComponents(AActor* act);
};
