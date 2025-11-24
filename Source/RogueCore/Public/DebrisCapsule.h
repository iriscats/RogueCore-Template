#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DebrisCapsule.generated.h"

USTRUCT(BlueprintType)
struct FDebrisCapsule {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ID;
    
    FVector Start;
    FVector End;
    float Radius;
    ROGUECORE_API FDebrisCapsule();
};
