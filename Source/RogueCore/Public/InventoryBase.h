#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DelegateDelegate.h"
#include "EquippedActorData.h"
#include "Templates/SubclassOf.h"
#include "InventoryBase.generated.h"

class AActor;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UInventoryBase : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnEquippedActorChanged;
    
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ActorsSelectable, meta=(AllowPrivateAccess=true))
    TArray<AActor*> ActorsSelectable;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ActorsNonSelectable, meta=(AllowPrivateAccess=true))
    TArray<AActor*> ActorsNonSelectable;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_EquippedActor, meta=(AllowPrivateAccess=true))
    FEquippedActorData ReplicatedEquippedActor;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FEquippedActorData EquippedActor;
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* LastEquippedActors[2];
public:
    UInventoryBase(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Server_SetEquippedActor(const FEquippedActorData& Actor, bool CallClientDelayed);
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Server_EquipExternalActor_Implementation(AActor* Actor);
    UFUNCTION(BlueprintCallable)
    void OnRep_EquippedActor(FEquippedActorData& OldActor);
 
    UFUNCTION()
    void OnRep_ActorsSelectable(TArray<AActor*> lastSelectable);
    UFUNCTION()
    void OnRep_ActorsNonSelectable(TArray<AActor*> lastNonSelectable);
    void GetSelectableActorsOfType(TSubclassOf<AActor> Class, TArray<AActor*>& OutActors, bool& OutResult);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<AActor*> GetSelectableActors() const;
    void GetNonSelectableActorsOfType(TSubclassOf<AActor> Class, TArray<AActor*>& OutActors, bool& OutResult);
    void EquipNull();
    void EquipLast();
    void EquipAtIndex(int32 Index, bool ignoreUsing);
    bool CanSelectActor(const AActor* Actor) const;
};
