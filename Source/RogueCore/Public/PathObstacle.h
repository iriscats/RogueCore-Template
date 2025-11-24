#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PathObstacle.generated.h"

USTRUCT(BlueprintType)
struct FPathObstacle {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector3f position;
    
    float Radius;
    ROGUECORE_API FPathObstacle();
};
