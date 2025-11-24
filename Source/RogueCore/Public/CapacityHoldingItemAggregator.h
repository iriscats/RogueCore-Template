#pragma once
#include "CoreMinimal.h"
#include "CapacityBasedItemAggregator.h"
#include "RejoinListener.h"
#include "Upgradable.h"
#include "CapacityHoldingItemAggregator.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCapacityHoldingItemAggregator : public UCapacityBasedItemAggregator, public IUpgradable, public IRejoinListener {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_MaxAmmo, meta=(AllowPrivateAccess=true))
    int32 MaxAmmo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_AmmoCount, meta=(AllowPrivateAccess=true))
    int32 AmmoCount;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseRejoin;
    bool IsAmmoReserve;
    bool Upgradable;
    UCapacityHoldingItemAggregator(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void UseAmmo(int32 count);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetMaxAmmo(int32 InMaxAmmo, bool InChangeCurrentAmount);
    void SetAmmo(int32 amount);
    void Resupply(float percentage);
    UFUNCTION()
    void OnRep_MaxAmmo();
    UFUNCTION()
    void OnRep_AmmoCount();
    void AddAmmo(int32 amount);
    // Fix for true pure virtual functions not being implemented
};
