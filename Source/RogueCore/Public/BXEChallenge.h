#pragma once
#include "CoreMinimal.h"
#include "BXEMissionStatContext.h"
#include "MilestoneAsset.h"
#include "BXEChallenge.generated.h"

class UObject;
UCLASS(Blueprintable)
class ROGUECORE_API UBXEChallenge : public UMilestoneAsset {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBXEMissionStatContext Context;
    
    UBXEChallenge();
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    bool IsChallengeCompleted(const UObject* WorldContext) const;
};
