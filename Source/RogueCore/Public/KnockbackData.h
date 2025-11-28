#pragma once
#include "CoreMinimal.h"

#include "KnockbackData.generated.h"

USTRUCT(BlueprintType)
struct FKnockbackData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Direction = FVector::ZeroVector;
    
    float Force;
    float Progress;

};
