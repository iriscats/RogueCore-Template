#pragma once
#include "CoreMinimal.h"
#include "SavableDataAsset.h"
#include "IntelChallenge.generated.h"

UCLASS(Abstract, Blueprintable)
class UIntelChallenge : public USavableDataAsset {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Description;
    
    int32 IntelReward;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsActive;
    UIntelChallenge();
    UFUNCTION(BlueprintCallable)
    void SetStatValue(const float NewValue);
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnStopTracking();
    UFUNCTION()
    void OnStartTracking_Implementation();
    void MarkChallengeComplete();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetTargetValue_Implementation() const;
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetStatValueAsInt() const;
    float GetStatValue() const;
    int32 GetIntelReward() const;
    void BroadcastComplete();
};
