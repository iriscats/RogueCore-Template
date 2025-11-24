#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DrillOperationData.generated.h"

USTRUCT(BlueprintType)
struct FDrillOperationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 OperationNumber;
    
    FVector HitPos;
    FVector Dir;
    FVector CarveSize;
    float CarveNoise;
    ROGUECORE_API FDrillOperationData();
};
