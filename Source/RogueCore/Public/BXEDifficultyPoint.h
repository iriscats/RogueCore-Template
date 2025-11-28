#pragma once
#include "CoreMinimal.h"

#include "Templates/SubclassOf.h"
#include "TimesPerPlayerCount.h"
#include "BXEDifficultyPoint.generated.h"

class UDialogDataAsset;
class UEnemyWaveController;
class UMusicLibrary;
USTRUCT(BlueprintType)
struct FBXEDifficultyPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Name;
    
    FTimesPerPlayerCount TimesPerPlayerCount;
    float PreemptiveWarningTime;
    UDialogDataAsset* PreemptiveWarningShout;
    FLinearColor Color;
    float EnemyCountScale;
    float CorruptedEnemyChance;
    TSubclassOf<UEnemyWaveController> WaveAtStart;
    UMusicLibrary* StartMusic;
    UDialogDataAsset* MissionControlStartShout;
    float MissionControlStartShoutRepeatInterval;
    ROGUECORE_API FBXEDifficultyPoint();
};
