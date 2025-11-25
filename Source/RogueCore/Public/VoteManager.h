#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DelegateDelegate.h"
#include "VoteData.h"
#include "VoteManager.generated.h"

class URunManager;
class UVoteOptionAction;
class UVoteOptionPool;
UCLASS(Blueprintable)
class ROGUECORE_API UVoteManager : public UObject {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnVoteDone;
    
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    URunManager* RunManager;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVoteData VoteData;
    TArray<UVoteOptionAction*> ExcludeVoteOption;
    UVoteManager();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, meta=(WorldContext="WorldContext"))
    void StartVote(UObject* WorldContext, UVoteOptionPool* InVotePool, int32 Seed);
};
