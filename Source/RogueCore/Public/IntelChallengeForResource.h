#pragma once
#include "CoreMinimal.h"
#include "IntelChallenge.h"
#include "IntelChallengeForResource.generated.h"

class UCappedResource;
class UPlanetZone;
class UResourceData;
UCLASS(Abstract, Blueprintable)
class UIntelChallengeForResource : public UIntelChallenge {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    UResourceData* RequiredResource;

    

    int32 RequiredAmount;

    UPlanetZone* RequiredZone;

    bool RequireMutator;

    bool AllowCollectionOverMultipleRuns;

    bool CanTeammatesDeposit;

    UIntelChallengeForResource();

    UFUNCTION(BlueprintCallable)

    void OnResourceIncreased(UCappedResource* Resource, const float ChangeAmount);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UResourceData* RequiredResource;
    
    int32 RequiredAmount;
    UPlanetZone* RequiredZone;
    bool RequireMutator;
    bool AllowCollectionOverMultipleRuns;
    bool CanTeammatesDeposit;
    UIntelChallengeForResource();
private:
    UFUNCTION(BlueprintCallable)
    void OnResourceIncreased(UCappedResource* Resource, const float ChangeAmount);
    void OnResourceDeposited(UResourceData* Resource, const float change);
};
