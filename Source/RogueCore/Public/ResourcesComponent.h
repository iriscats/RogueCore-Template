#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ResourceAddedDelegate.h"
#include "ResourceAddedSignatureDelegate.h"
#include "ResourceChangedSignatureDelegate.h"
#include "ResourceFullSignatureDelegate.h"
#include "ResourcesComponent.generated.h"

class UCappedResource;
class UResourceData;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UResourcesComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section


public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FResourceChangedSignature OnResourceChanged;
    
    FResourceAddedSignature OnResourceIncreased;
    FResourceFullSignature OnResourceFull;
    FResourceAdded OnResourceAdded;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Resources, meta=(AllowPrivateAccess=true))
    TArray<UCappedResource*> Resources;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ResourceCap;
    UResourcesComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void ResourceIncreased(UCappedResource* Resource, float Delta);
    void ResourceFull(UCappedResource* Resource);
    void ResourceChanged(UCappedResource* Resource, float CurrentAmount);
    void RemoveAllResources();
    UFUNCTION()
    void OnRep_Resources();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetXPFromResourceMap(const TMap<UResourceData*, float>& NewResources);
    int32 GetXpFromMining() const;
    static TMap<UResourceData*, float> GetSeparateResourcesFromMap(const TMap<UResourceData*, float>& NewResources);
    float GetResourceAmount(const UResourceData* InData) const;
    UCappedResource* GetResource(UResourceData* Data, bool createIfAmountIsZero);
    float GetCapacityPct() const;
    TArray<UCappedResource*> GetAllResources() const;
    float AddResource(UResourceData* InData, float amount);
};
