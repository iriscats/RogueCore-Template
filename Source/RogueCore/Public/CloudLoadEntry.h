#pragma once
#include "CoreMinimal.h"
#include "CloudLoadEntry.generated.h"

USTRUCT(BlueprintType)
struct FCloudLoadEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString RawData;
    
    FString TimeUTC;
    ROGUECORE_API FCloudLoadEntry();
};
