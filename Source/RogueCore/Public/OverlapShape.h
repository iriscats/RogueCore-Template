#pragma once
#include "CoreMinimal.h"
#include "OverlapShape.generated.h"

USTRUCT(BlueprintType)
struct FOverlapShape {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Radius;
    
    float Height;
    float Width;
    float Depth;
    ROGUECORE_API FOverlapShape();
};
