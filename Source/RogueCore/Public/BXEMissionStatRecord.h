#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BXEMissionStatRecord.generated.h"

USTRUCT(BlueprintType)
struct FBXEMissionStatRecord {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid MissionStatID;
    
    FGuid RunId;
    FGuid WeaponID;
    int32 count;
    ROGUECORE_API FBXEMissionStatRecord();
};
