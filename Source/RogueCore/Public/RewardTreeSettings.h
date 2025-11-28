#pragma once
#include "CoreMinimal.h"

#include "Engine/DataAsset.h"
#include "RewardTreeSettings.generated.h"

UCLASS(Blueprintable)
class ROGUECORE_API URewardTreeSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NodeSize;
    
    float NodeSnapSize;
    float SquiggleWithinDistance;
    FVector2D CanvasSize;
    URewardTreeSettings();
};
