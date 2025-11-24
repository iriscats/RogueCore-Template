#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PlacementObstruction.generated.h"

USTRUCT(BlueprintType)
struct FPlacementObstruction {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float Range;
    
    FVector Location;
    ROGUECORE_API FPlacementObstruction();
};
