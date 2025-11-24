#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ERarityWeightType.h"
#include "BXEUnlockCollection.generated.h"

class UBXEUnlockBase;
UCLASS(Abstract, Blueprintable)
class ROGUECORE_API UBXEUnlockCollection : public UPrimaryDataAsset {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERarityWeightType RarityWeightType;

    UBXEUnlockCollection();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetSkipRewards(TArray<UBXEUnlockBase*>& OutSkipRewards) const;
    void GetAllUnlocks(TSet<UBXEUnlockBase*>& OutAllUnlocks) const;
private:
    bool AddDroneUnlocks;
    bool LockTelemetryIdentifier;
    FString TelemetryIdentifier;
};
