#pragma once
#include "CoreMinimal.h"
#include "CraftingCost.h"
#include "EUpgradeClass.h"
#include "EUpgradeTiers.h"
#include "EWeaponOverviewModifierType.h"
#include "ItemUpgradeStatText.h"
#include "RefundableInterface.h"
#include "SavableDataAsset.h"
#include "Templates/SubclassOf.h"
#include "UpgradeValues.h"
#include "ItemUpgrade.generated.h"

class AActor;
class AFSDPlayerState;
class UItemUpgrade;
class UItemUpgradeCategory;
class UItemUpgradeElement;
class UItemUpgradeFilter;
class UResourceData;
UCLASS(Blueprintable, EditInlineNew)
class ROGUECORE_API UItemUpgrade : public USavableDataAsset, public IRefundableInterface {
    GENERATED_BODY()
    

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FItemUpgradeSignature, UItemUpgrade*, upgrade);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FItemUpgradeSignature OnCrafted;
    FItemUpgradeSignature OnEquipped;
    FItemUpgradeSignature OnUnequipped;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UItemUpgradeFilter* SelectionFilter;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Name;
    FText Description;
    int32 Cost;
    FText GeneralIconType;
    EWeaponOverviewModifierType ModifierType;
    bool UseOldCost;
    EUpgradeTiers UpgradeTier;
    EUpgradeClass upgradeClass;
    UItemUpgradeCategory* Category;
    TMap<UResourceData*, float> UpgradeCraftingCost;
    TArray<UResourceData*> ResourceCost;
    TArray<UItemUpgradeElement*> Elements;
    TArray<FItemUpgradeStatText> StatTexts;
    UItemUpgrade();
    UFUNCTION(BlueprintCallable)
    void UnequipUpgrade(TSubclassOf<AActor> itemClass, AFSDPlayerState* PlayerState);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FItemUpgradeStatText> GetUpgradeStatTexts() const;
    static FText GetUpgradeName(UItemUpgrade* upgrade);
    TArray<FCraftingCost> GetUpgradeCost() const;
    FString GetSourceName();
    bool GetIsAmountPercentage() const;
    static FUpgradeValues GetGenericUpgradedValue(TSubclassOf<AActor> Item, AFSDPlayerState* Player, UItemUpgrade* NewUpgradeClass);
    float GetCreditsCost() const;
    float GetAmount() const;
    void EquipUpgrade(TSubclassOf<AActor> itemClass, AFSDPlayerState* PlayerState);
    // Fix for true pure virtual functions not being implemented
};
