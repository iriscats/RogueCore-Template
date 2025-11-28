#pragma once
#include "CoreMinimal.h"

#include "StairInfo.generated.h"

USTRUCT(BlueprintType)
struct FStairInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Location = FVector::ZeroVector;
    
    FRotator Rotation;
    float Length;
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int8 StairIndex = 0;

};
