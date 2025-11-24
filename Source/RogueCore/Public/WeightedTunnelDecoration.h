#pragma once
#include "CoreMinimal.h"
#include "WeightedTunnelDecoration.generated.h"

class ATunnelDecoration;
USTRUCT(BlueprintType)
struct FWeightedTunnelDecoration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ATunnelDecoration> TunnelDecoration;
    
    float SpawnWeight;
    ROGUECORE_API FWeightedTunnelDecoration();
};
