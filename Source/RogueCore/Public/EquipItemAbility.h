#pragma once
#include "CoreMinimal.h"
#include "AbilityComponent.h"
#include "Templates/SubclassOf.h"
#include "EquipItemAbility.generated.h"

class AAbilityItem;
class AItem;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UEquipItemAbility : public UAbilityComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))

    TWeakObjectPtr<AItem> PreviouslyEquippedItem;

    bool EquipOnDeactivate;

    UEquipItemAbility(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AAbilityItem> ItemToEquip;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ItemInstance, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AAbilityItem> ItemInstance;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AItem> PreviouslyEquippedItem;
    bool EquipOnDeactivate;
    UEquipItemAbility(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnRep_ItemInstance();
};
