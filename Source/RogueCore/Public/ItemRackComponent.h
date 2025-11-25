#pragma once
#include "CoreMinimal.h"
#include "ItemRackDelegateDelegate.h"
#include "SingleUsableComponent.h"
#include "ItemRackComponent.generated.h"

class AActor;
class APlayerCharacter;
class URackableItemComponent;
class USceneComponent;
class UUsableComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UItemRackComponent : public USingleUsableComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemRackDelegate OnHasItemChanged;
    
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UUsableComponent* UsableComponent;
    USceneComponent* AttachToComponent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AttachPointSocket;
    bool AttachToSocket;
    int32 RackKey;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, ReplicatedUsing=OnRep_Item, meta=(AllowPrivateAccess=true))
    URackableItemComponent* Item;
    UItemRackComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void RackItem(AActor* NewItem, APlayerCharacter* Character);
    UFUNCTION()
    void OnRep_Item(URackableItemComponent* OldItem);
    void InitializeRackedItem(URackableItemComponent* rackable);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasRackedItem() const;
    bool CanRackItem(AActor* NewItem) const;
};
