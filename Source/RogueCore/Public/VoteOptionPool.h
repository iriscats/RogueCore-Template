#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "VoteOptionPool.generated.h"

class UVoteOptionAction;
UCLASS(Blueprintable)
class UVoteOptionPool : public UPrimaryDataAsset {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TSet<UVoteOptionAction*> VoteOptionActions;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool LockTelemetryIdentifier;
    FString TelemetryIdentifier;
    UVoteOptionPool();
    UFUNCTION(BlueprintCallable)
    TArray<UVoteOptionAction*> GetVoteOptionActions();
};
