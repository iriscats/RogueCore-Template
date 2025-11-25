#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "DelegateDelegate.h"
#include "VoteData.h"
#include "VoteParticipantComponent.generated.h"

class AFSDPlayerState;
class UVoteWidget;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UVoteParticipantComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVoteData VoteData;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnVoteDone;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UVoteWidget* VoteWidget;
    UVoteParticipantComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_Vote(int32 InVoteIndex);
    UFUNCTION(BlueprintCallable, Server, Unreliable)
    void Server_RecordParticipantCursor(const FVector2f& Pos);
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void Client_SetVoteData(const FVoteData& InData);
    UFUNCTION(BlueprintCallable, Client, Unreliable)
    void Client_ReceiveParticipantCursor(AFSDPlayerState* InPlayer, const FVector2f& InPos);
};
