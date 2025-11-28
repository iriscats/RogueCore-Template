#pragma once
#include "CoreMinimal.h"

#include "DirtQueryResult.generated.h"

USTRUCT(BlueprintType)
struct FDirtQueryResult {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> DirtPoints;
    
    TArray<FVector> QueryPointsOnTerrain;
    ROGUECORE_API FDirtQueryResult();
};
