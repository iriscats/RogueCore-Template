#pragma once
#include "CoreMinimal.h"
#include "ResourceBasedObjective.h"
#include "GatheItemsObjective.generated.h"

class UCappedResource;
class UCollectableResourceData;
UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UGatheItemsObjective : public UResourceBasedObjective {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ItemsRequired;
    
    float ItemsSpawnedModifier;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ItemsCollected, meta=(AllowPrivateAccess=true))
    int32 ItemsCollected;
    UCollectableResourceData* ItemResource;
    UGatheItemsObjective(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnResourceChanged(UCappedResource* CappedResource, float amount);
    UFUNCTION()
    void OnRep_ItemsCollected(int32 prevAmount);
};
