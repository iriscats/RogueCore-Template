#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AnimatedItem.h"
#include "Templates/SubclassOf.h"
#include "CalldownItem.generated.h"

class AActor;
class ARessuplyPod;
class UItemPlacerAggregator;
class UResourceData;
UCLASS(Blueprintable, NoExport)
class ACalldownItem : public AAnimatedItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemPlacerAggregator> ItemPlacerClass;

    TSubclassOf<ARessuplyPod> SupplyPodClass;
    UResourceData* ResouceRequired;
    FText OrderDescription;
    FText LogText;
    TSubclassOf<AActor> ResupplyBeacon;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UItemPlacerAggregator* ItemPlacerInstance;
    float CoolDown;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float CooldownRemaining;
    ACalldownItem(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_Call_Resupply(const FVector& Location);
};
