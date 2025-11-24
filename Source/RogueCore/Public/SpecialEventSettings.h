#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Curves/CurveFloat.h"
#include "SpecialEventSettings.generated.h"

class AEventRewardFrame;
class UDebrisPositioning;
class USpecialEvent;
UCLASS(Blueprintable)
class USpecialEventSettings : public UDataAsset {
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<USpecialEvent*> MachineEvents;
    
    FRuntimeFloatCurve ME_SpawnChanceMissionLengthCurve;
    TArray<USpecialEvent*> OtherSpecialEvents;
    FRuntimeFloatCurve Other_SpawnChanceMissionLengthCurve;
    TSoftClassPtr<AEventRewardFrame> EventRewardFrameClass;
    UDebrisPositioning* EventRewardFramePositioning;
    float EventRewardRadius;
    float CreditsReward;
    float XPReward;
    USpecialEventSettings();
};
