#pragma once
#include "CoreMinimal.h"
#include "ResourceBasedObjective.h"
#include "GatherGemsObjective.generated.h"

class UCappedResource;
class UGemResourceData;
UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UGatherGemsObjective : public UResourceBasedObjective {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 GemsRequired;
    
    float GemsSpawnedModifier;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_GemsCollected, meta=(AllowPrivateAccess=true))
    int32 GemsCollected;
    UGemResourceData* GemResource;
    UGatherGemsObjective(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnResourceChanged(UCappedResource* CappedResource, float amount);
    UFUNCTION()
    void OnRep_GemsCollected(int32 prevAmount);
};
