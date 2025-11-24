#pragma once
#include "CoreMinimal.h"
#include "CoolDownProgressStyle.h"
#include "RejoinListener.h"
#include "ThrowableItem.h"
#include "UpgradableGear.h"
#include "ShieldGeneratorItem.generated.h"

class UCapacityHoldingItemAggregator;
class UDialogDataAsset;
UCLASS(Blueprintable, NoExport)
class AShieldGeneratorItem : public AThrowableItem, public IUpgradableGear, public IRejoinListener {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCapacityHoldingItemAggregator* ChargeCapacity;
    
    UCapacityHoldingItemAggregator* CarryCapacity;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RechargeDuration;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_UnchargedCount, meta=(AllowPrivateAccess=true))
    int32 UnchargedCount;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float RechargeProgress;
    float SupplyStatusWeight;
    UDialogDataAsset* ShoutRecarged;
    FCoolDownProgressStyle RechargeProgressUI;
    AShieldGeneratorItem(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveGeneratorReturned();
    void ReceiveGeneratorRechargeProgress(float Progress);
    void ReceiveGeneratorRecharged();
    UFUNCTION(BlueprintCallable)
    void OnRep_UnchargedCount(int32 OldCount);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsRecharging() const;
    void GeneratorReturned();
    // Fix for true pure virtual functions not being implemented
};
