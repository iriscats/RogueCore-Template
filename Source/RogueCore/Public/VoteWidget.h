#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VoteData.h"
#include "VoteOptionInstance.h"
#include "VoteParticipant.h"
#include "WindowWidget.h"
#include "VoteWidget.generated.h"

class AFSDPlayerState;
class UVoteParticipantComponent;
UCLASS(Abstract, Blueprintable, EditInlineNew)
class UVoteWidget : public UWindowWidget {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UVoteParticipantComponent> participant;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVoteData VoteData;
    UVoteWidget();
    UFUNCTION(BlueprintCallable)
    bool Vote(int32 InVoteIndex);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveVotingCompleted(int32 InWinningIndex);
    void ReceiveVoteOptionsChanged(const TArray<FVoteOptionInstance>& InVoteOptions);
    void ReceiveTimerStarted();
    void ReceiveParticipantsChanged(const TArray<FVoteParticipant>& InParticipants);
    void ReceiveParticipantCursorChanged(AFSDPlayerState* InPlayerState, FVector2D InViewPortPos);
    void ReceiveDataChanged();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsVoteFinishing() const;
    void GetVotedBy(int32 OptionIndex, TArray<FString>& OutVotedByNames, int32& OutMaxVotes);
};
