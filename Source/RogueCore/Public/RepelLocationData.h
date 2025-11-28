#pragma once
#include "CoreMinimal.h"

#include "RepelLocationData.generated.h"

USTRUCT(BlueprintType)
struct FRepelLocationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector SourceLocation = FVector::ZeroVector;
    
    float Radius;
    float HalfHeight;
    FVector ExtraVelocity;
    float MinStrength;
    float MaxStrength;

};
