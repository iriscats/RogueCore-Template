#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IKEffectorData.generated.h"

USTRUCT(BlueprintType)
struct FIKEffectorData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform Transform;
    
    FName bone;
    float Strength;
    ROGUECORE_API FIKEffectorData();
};
