#pragma once
#include "CoreMinimal.h"
#include "EDiscordBiomeType.h"
#include "EDiscordMissionType.h"
#include "DiscordFSDRichPresence.generated.h"

USTRUCT(BlueprintType)
struct FDiscordFSDRichPresence {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString State;
    
    FString details;
    FString matchSecret;
    FString joinSecret;
    FString partyId;
    FString smallImageText;
    FString LargeImageText;
    int32 startTimestamp;
    int32 partySize;
    EDiscordBiomeType BiomeType;
    EDiscordMissionType MissionType;
    bool bIsPureSolo;
    ROGUECORE_API FDiscordFSDRichPresence();
};
