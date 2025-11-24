#pragma once
#include "CoreMinimal.h"
#include "BXEMissionStatRecord.h"
#include "BXEMissionStats.generated.h"

USTRUCT(BlueprintType)
struct FBXEMissionStats {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FBXEMissionStatRecord> Records;

    ROGUECORE_API FBXEMissionStats();
protected:
};
