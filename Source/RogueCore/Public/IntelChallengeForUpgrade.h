#pragma once
#include "CoreMinimal.h"
#include "EUnlockType.h"
#include "IntelChallenge.h"
#include "IntelChallengeForUpgrade.generated.h"

class UBXEUnlockBase;
UCLASS(Abstract, Blueprintable)
class UIntelChallengeForUpgrade : public UIntelChallenge {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EUnlockType RequiredType;
    
    int32 RequiredAmount;
    bool AllowCollectionOverMultipleRuns;
    UIntelChallengeForUpgrade();
 
    UFUNCTION(BlueprintCallable)
    void OnLevelUp(const int32 Level, const TArray<UBXEUnlockBase*>& Unlocks);
};
