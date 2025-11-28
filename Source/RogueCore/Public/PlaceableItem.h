#pragma once
#include "CoreMinimal.h"

#include "AnimatedItem.h"
#include "PlaceableInterface.h"
#include "Templates/SubclassOf.h"
#include "Upgradable.h"
#include "PlaceableItem.generated.h"

class AActor;
class UCapacityHoldingItemAggregator;
class UItemPlacerAggregator;
UCLASS(Blueprintable)
class APlaceableItem : public AAnimatedItem, public IUpgradable, public IPlaceableInterface {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCapacityHoldingItemAggregator* Capacity;
    
    UItemPlacerAggregator* ItemPlacer;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> PlacableClass;
    APlaceableItem(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SpawnItem(FVector Location);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveItemSpawned(AActor* SpawnedActor);
    UFUNCTION(BlueprintCallable)
    void OnCarriedAmountChanged(int32 newAmount);
    // Fix for true pure virtual functions not being implemented
};
