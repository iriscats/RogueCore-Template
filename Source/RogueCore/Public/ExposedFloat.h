#pragma once
#include "CoreMinimal.h"
#include "ExposedProperty.h"
#include "ExposedFloat.generated.h"

USTRUCT(BlueprintType)
struct FExposedFloat : public FExposedProperty {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PropertyName;
    
    FText Description;
    float MinValue;
    float MaxValue;
    ROGUECORE_API FExposedFloat();
};
