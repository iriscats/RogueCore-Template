#pragma once
#include "CoreMinimal.h"
#include "EPickaxePartLocation.h"
#include "DefaultPickaxeParts.generated.h"

class UPickaxePart;
USTRUCT(BlueprintType)
struct FDefaultPickaxeParts {
    GENERATED_BODY()
    
public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EPickaxePartLocation, UPickaxePart*> Parts;
    
    ROGUECORE_API FDefaultPickaxeParts();
};
