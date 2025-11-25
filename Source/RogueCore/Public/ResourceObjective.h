#pragma once
#include "CoreMinimal.h"
#include "ResourceBasedObjective.h"
#include "ResourceObjective.generated.h"

class UCappedResource;
class UResourceData;
UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UResourceObjective : public UResourceBasedObjective {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section


public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UResourceData* Resource;
    
    float ResourcesRequired;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ResourcesCollected, meta=(AllowPrivateAccess=true))
    float ResourcesCollected;
    float ResourceBuffer;
    float RoundToNearest;
    FText ObjectivesText;
    FText CreditsRewardText;
    UResourceObjective(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnResourceChanged(UCappedResource* CappedResource, float amount);
    UFUNCTION()
    void OnRep_ResourcesCollected(float prevAmount);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetRequiredAmount(float missionScaling) const;
};
