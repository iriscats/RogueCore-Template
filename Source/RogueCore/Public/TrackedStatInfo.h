#pragma once
#include "CoreMinimal.h"
#include "TrackedStatInfo.generated.h"

class UDataAsset;
class UMissionStat;
class UTexture2D;
USTRUCT(BlueprintType)
struct FTrackedStatInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMissionStat* Stat;
    
    FText Name;
    TSoftObjectPtr<UTexture2D> Image;
    UDataAsset* assetReference;
    ROGUECORE_API FTrackedStatInfo();
};
