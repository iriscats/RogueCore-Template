#pragma once
#include "CoreMinimal.h"

#include "TunnelPath.generated.h"

USTRUCT(BlueprintType)
struct FTunnelPath {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> Path;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<int32> NoCarveAtIndices;
    ROGUECORE_API FTunnelPath();
};
