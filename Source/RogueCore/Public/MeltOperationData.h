#pragma once
#include "CoreMinimal.h"

#include "MeltOperationData.generated.h"

USTRUCT(BlueprintType)
struct FMeltOperationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 OperationNumber;
    
    TArray<FVector> Points;
    float Radius;
    ROGUECORE_API FMeltOperationData();
};
