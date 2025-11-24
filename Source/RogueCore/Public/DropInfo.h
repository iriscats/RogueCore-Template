#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DropInfo.generated.h"

USTRUCT(BlueprintType)
struct FDropInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector From;
    
    FVector To;
    bool HasLanded;
    ROGUECORE_API FDropInfo();
};
