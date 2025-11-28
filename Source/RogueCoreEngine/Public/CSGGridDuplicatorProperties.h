#pragma once
#include "CoreMinimal.h"

#include "CSGGridDuplicatorProperties.generated.h"

USTRUCT(BlueprintType)
struct FCSGGridDuplicatorProperties {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumA = 0;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumB = 0;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector DirectionA = FVector::ZeroVector;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector DirectionB = FVector::ZeroVector;

};

