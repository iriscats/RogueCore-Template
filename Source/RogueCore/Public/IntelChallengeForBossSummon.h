#pragma once
#include "CoreMinimal.h"
#include "ERunDepth.h"
#include "IntelChallenge.h"
#include "IntelChallengeForBossSummon.generated.h"

class AActor;
UCLASS(Abstract, Blueprintable)
class UIntelChallengeForBossSummon : public UIntelChallenge {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    TArray<TSoftClassPtr<AActor>> AllowedBosses;

    

    int32 RequiredSummonAmount;

    ERunDepth RequiredRunDepth;

    UIntelChallengeForBossSummon();

    UFUNCTION(BlueprintCallable)

    void OnBossSummoned(AActor* boss);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AActor>> AllowedBosses;
    
    int32 RequiredSummonAmount;
    ERunDepth RequiredRunDepth;
    UIntelChallengeForBossSummon();
private:
    UFUNCTION(BlueprintCallable)
    void OnBossSummoned(AActor* boss);
};
