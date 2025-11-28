#pragma once
#include "CoreMinimal.h"

#include "AnimatedItem.h"
#include "Templates/SubclassOf.h"
#include "Upgradable.h"
#include "RecallableItem.generated.h"

class AActor;
class ARecallableActor;
class ARedeployableSentryGun;
UCLASS(Abstract, Blueprintable)
class ARecallableItem : public AAnimatedItem, public IUpgradable {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ARecallableActor> ItemType;
    
    UPROPERTY(EditAnywhere, Transient, ReplicatedUsing=OnRep_ActiveItems, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<ARecallableActor>> ActiveItems;
    ARecallableItem(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerSpawnItem(const FVector& Location, const FRotator& Rotation);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveOnItemSpawned(ARecallableActor* Item);
    UFUNCTION(BlueprintCallable)
    void OnRep_ActiveItems();
    void ItemReturnFinished(AActor* Item, bool success);
    void ItemDestroyed(ARedeployableSentryGun* Item);
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CanSpawnItem(const FVector& Location, const FRotator& Rotation);
    // Fix for true pure virtual functions not being implemented
};
