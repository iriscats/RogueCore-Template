#pragma once
#include "CoreMinimal.h"
#include "SavableDataAsset.h"
#include "SeasonEventData.generated.h"

class UTexture2D;
UCLASS(Blueprintable)
class ROGUECORE_API USeasonEventData : public USavableDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Name;
    
    int32 PerformancePoints;
    int32 PerformancePointsOnFail;
    TSoftObjectPtr<UTexture2D> Icon;
    USeasonEventData();
};
