#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataAsset.h"
#include "SeasonSettings.generated.h"

class UCurveFloat;
class UMissionStat;
class USeason;
class USeasonChallenge;
UCLASS(Blueprintable)
class USeasonSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USeason* CurrentSeason;
    
    int32 MaxActiveChallenges;
    TArray<USeasonChallenge*> SeasonChallenges;
    int32 XPPerLevel;
    UCurveFloat* XPToPerforcemancePointsCurve;
    int32 TreeOfVanitySnapSize;
    float SpecialChallengeChange;
    UMissionStat* HeartsColledtedStat;
    FIntPoint SporeTowerPlagueGainRange;
    int32 HeartsPerScrip;
    int32 NumberOfScriptsFromPlague;
    USeasonSettings();
};
