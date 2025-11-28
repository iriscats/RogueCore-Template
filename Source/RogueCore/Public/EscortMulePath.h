#pragma once
#include "CoreMinimal.h"

#include "EscortMulePath.generated.h"

USTRUCT(BlueprintType)
struct FEscortMulePath {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> Path;
    
    ROGUECORE_API FEscortMulePath();
};
