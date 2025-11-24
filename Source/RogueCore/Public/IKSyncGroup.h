#pragma once
#include "CoreMinimal.h"
#include "IKSyncGroup.generated.h"

USTRUCT(BlueprintType)
struct FIKSyncGroup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> LegNumbers;
    
    int32 MinDownCount;
    ROGUECORE_API FIKSyncGroup();
};
