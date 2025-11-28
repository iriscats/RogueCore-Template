#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EInputKeys.h"
#include "ItemDispenserDelegateDelegate.h"
#include "Templates/SubclassOf.h"
#include "ItemDispenser.generated.h"

class ACarriableItem;
class APlayerCharacter;
class UInstantUsable;
class USceneComponent;
UCLASS(Blueprintable)
class AItemDispenser : public AActor {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    UInstantUsable* usable;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemDispenserDelegate OnItemSpawned;
    FItemDispenserDelegate OnItemTaken;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> ItemHistory;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ACarriableItem> itemClass;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_SpawnedItem, meta=(AllowPrivateAccess=true))
    AActor* spawnedItem;
    float ItemSpawnTime;
    float InitialItemSpawnTime;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsOpen, meta=(AllowPrivateAccess=true))
    bool IsOpen;
    bool KillItemsOnDestuction;
    AItemDispenser(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SpawnItem();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void Open();
    void OnUsed(APlayerCharacter* User, EInputKeys Key);
    UFUNCTION()
    void OnRep_SpawnedItem(AActor* OldItem);
    UFUNCTION()
    void OnRep_IsOpen();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPickedUpItem(AActor* Item);
    void OnOpenChanged(bool NewOpen);
    void OnItemSpawnedEvent(AActor* Item);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasItem() const;
    AActor* GetItem() const;
    void Close();
};
