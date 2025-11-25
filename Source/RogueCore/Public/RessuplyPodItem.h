#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AnimatedItem.h"
#include "Templates/SubclassOf.h"
#include "RessuplyPodItem.generated.h"

class AActor;
class ARessuplyPod;
class UItemPlacerAggregator;
class UObject;
UCLASS(Blueprintable, NoExport)
class ARessuplyPodItem : public AAnimatedItem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section


public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> ResupplyBeacon;
    
    TSubclassOf<UItemPlacerAggregator> ItemPlacerClass;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UItemPlacerAggregator* ItemPlacerInstance;
    TSubclassOf<ARessuplyPod> SupplyPodClass;
    int32 ResourceCost;
    FText OrderDescription;
    FText LogText;
    float CoolDown;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Used, meta=(AllowPrivateAccess=true))
    bool Used;
    ARessuplyPodItem(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_Call_Resupply(const FVector& Location);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveItemPlacerSpawned(UItemPlacerAggregator* InItemPlacer);
    UFUNCTION(BlueprintCallable)
    void OnRep_Used();
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    int32 GetResourceCost(UObject* WorldContextObject) const;
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UItemPlacerAggregator* GetActiveAggregator() const;
};
