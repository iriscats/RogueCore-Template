#pragma once
#include "CoreMinimal.h"
#include "EGameType.h"
#include "ESteamSearchRegion.h"
#include "ESteamServerJoinStatus.h"
#include "FSDServerSearchOptions.generated.h"

class UDifficultySetting;
USTRUCT(BlueprintType)
struct FFSDServerSearchOptions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESteamServerJoinStatus JoinStatus;
    
    ESteamSearchRegion SearchRegion;
    TArray<UDifficultySetting*> Difficulties;
    bool DeepDive;
    FString SearchString;
    int32 missionSeed;
    int32 GlobalMissionSeed;
    TArray<EGameType> GameTypes;
    ROGUECORE_API FFSDServerSearchOptions();
};
