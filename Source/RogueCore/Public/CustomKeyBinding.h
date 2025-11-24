#pragma once
#include "CoreMinimal.h"
#include "CustomKeyBinding.generated.h"

USTRUCT(BlueprintType)
struct FCustomKeyBinding {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ActionName;
    
    int32 Index;
    FKey Key;
    ROGUECORE_API FCustomKeyBinding();
};
