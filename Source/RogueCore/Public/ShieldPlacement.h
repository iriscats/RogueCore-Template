#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ShieldPlacement.generated.h"

USTRUCT(BlueprintType)
struct FShieldPlacement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Location;
    
    FRotator Rotation;
    ROGUECORE_API FShieldPlacement();
};
