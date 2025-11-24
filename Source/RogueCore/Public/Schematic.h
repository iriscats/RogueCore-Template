#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ESchematicState.h"
#include "SavableDataAsset.h"
#include "Schematic.generated.h"

class UFSDSaveGame;
class UObject;
class UPlayerCharacterID;
class UResourceData;
class USchematic;
class USchematicCategory;
class USchematicItem;
class USchematicPricingTier;
class USchematicRarity;
class UTexture;
UCLASS(Blueprintable, EditInlineNew)
class ROGUECORE_API USchematic : public USavableDataAsset {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSchematicDelegate, USchematic*, Schematic);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSchematicDelegate OnSchematicAddedToInventory;
    FSchematicDelegate OnSchematicReset;
    FSchematicDelegate OnSchematicBuilt;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USchematicCategory* Category;
    USchematicPricingTier* PricingTier;
    USchematicRarity* Rarity;
    UPlayerCharacterID* UsedByCharacter;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USchematicItem* Item;
    TMap<UResourceData*, int32> CraftingCost;
    bool CostIsLocked;
    USchematic();
    UFUNCTION(BlueprintCallable)
    void SetCraftingMaterialCost();
    void SetCostLocked(bool IsLocked);
    void ResetGivenReward(UFSDSaveGame* SaveGame);
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void RemoveSchematicFromPlayerInventory(UObject* WorldContext);
    void GiveRewardForFree(UFSDSaveGame* SaveGame);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetTitle() const;
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    ESchematicState GetSchematicState(UObject* WorldContext) const;
    USchematicItem* GetSchematicItem() const;
    TMap<UResourceData*, int32> GetResourceCost() const;
    FColor GetIconTint() const;
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    UTexture* GetIcon(UObject* WorldContextObject) const;
    FText GetDescription() const;
    bool CanAffordSchematic(UObject* WorldContext) const;
    void BuildSchematic(UObject* WorldContext);
    void AddSchematicToPlayerInventory(UObject* WorldContext);
};
