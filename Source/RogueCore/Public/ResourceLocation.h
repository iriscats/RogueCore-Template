#pragma once
#include "CoreMinimal.h"

#include "ResourceLocation.generated.h"

class UResourceData;
USTRUCT(BlueprintType)
struct FResourceLocation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Location = FVector::ZeroVector;
    
    UResourceData* Resource;
    float BaseAmount;

};
