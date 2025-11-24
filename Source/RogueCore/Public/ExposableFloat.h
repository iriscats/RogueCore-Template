#pragma once
#include "CoreMinimal.h"
#include "ExposableFloat.generated.h"

USTRUCT(BlueprintType)
struct FExposableFloat {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    bool Exposed;
    FText Description;
    float MinValue;
    float MaxValue;
    ROGUECORE_API FExposableFloat();
};
