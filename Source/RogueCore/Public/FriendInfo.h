#pragma once
#include "CoreMinimal.h"
#include "FriendInfo.generated.h"

USTRUCT(BlueprintType)
struct FFriendInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString DisplayName;
    
    FString RealName;
    FString UserId;
    bool IsOnline;
    bool IsPlaying;
    bool IsPlayingThisGame;
    bool IsJoinable;
    FString SessionId;
    bool HasVoiceSupport;
    FString PresenceStatus;
    ROGUECORE_API FFriendInfo();
};
