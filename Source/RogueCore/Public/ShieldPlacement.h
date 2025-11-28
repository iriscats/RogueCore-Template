#pragma once
#include "CoreMinimal.h"

#include "ShieldPlacement.generated.h"

USTRUCT(BlueprintType)
struct FShieldPlacement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Location = FVector::ZeroVector;
    
    FRotator Rotation;

};
