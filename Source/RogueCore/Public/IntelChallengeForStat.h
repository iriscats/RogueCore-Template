#pragma once
#include "CoreMinimal.h"
#include "IntelChallenge.h"
#include "IntelChallengeForStat.generated.h"

class UMissionStat;
class UObject;
class UPlanetZone;
UCLASS(Abstract, Blueprintable)
class UIntelChallengeForStat : public UIntelChallenge {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMissionStat* RequiredStat;
    
    int32 RequiredAmount;
    UPlanetZone* RequiredZone;
    bool RequireMutator;
    UIntelChallengeForStat();
 
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void OnStatUpdated(UObject* WorldContext, UMissionStat* ChangedStat, float Value, float change);
};
