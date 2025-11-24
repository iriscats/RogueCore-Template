#pragma once
#include "CoreMinimal.h"
#include "VoteOptionInstance.h"
#include "VoteParticipant.h"
#include "VoteData.generated.h"

class AFSDPlayerState;
USTRUCT(BlueprintType)
struct FVoteData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bVoting;
    
    TArray<FVoteOptionInstance> VoteOptions;
    TArray<FVoteParticipant> Participants;
    int32 VoteWinnerIndex;
    int32 Timeout;
    bool CountDownStarted;
    FString TelemetryIdentifier;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AFSDPlayerState> PausedByPlayer;
    int32 VoteID;
    ROGUECORE_API FVoteData();
};
