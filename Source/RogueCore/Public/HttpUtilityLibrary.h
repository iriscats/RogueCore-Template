#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "HttpUtilityLibrary.generated.h"

UCLASS(Blueprintable)
class ROGUECORE_API UHttpUtilityLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UHttpUtilityLibrary();
};
