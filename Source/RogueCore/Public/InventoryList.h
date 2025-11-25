#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EItemCategory.h"
#include "ItemFilterDelegateDelegate.h"
#include "Templates/SubclassOf.h"
#include "InventoryList.generated.h"

class AActor;
class UItemID;
class UMaterialInterface;
class UObject;
class UTexture2D;
UCLASS(Blueprintable)
class ROGUECORE_API UInventoryList : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> IconWeaponSetOutline;
    
    TSoftObjectPtr<UTexture2D> IconWeaponSetFill;
    TSoftObjectPtr<UMaterialInterface> LaserpointerMarkerMaterial;
    TSoftObjectPtr<UMaterialInterface> LaserpointerBeamMaterial;
    UItemID* LaserPointerItem;
    UItemID* TerrainScannerItem;
    UItemID* ResupplyItem;
 
    TArray<UItemID*> Armors;
    TArray<UItemID*> Flares;
    TArray<UItemID*> MiningTools;
    UInventoryList();
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    UItemID* GetPreviousUnlockedItem(UObject* WorldContextObject, EItemCategory Category, UItemID* currentItem) const;
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UItemID* GetPreviousItem(EItemCategory Category, UItemID* currentItem) const;
    int32 GetNumberOfItems(EItemCategory Category) const;
    UItemID* GetNextUnlockedItem(UObject* WorldContextObject, EItemCategory Category, UItemID* currentItem) const;
    UItemID* GetNextItem(EItemCategory Category, UItemID* currentItem) const;
    TArray<TSubclassOf<AActor>> GetLoadedItemListFiltered(EItemCategory Category, FItemFilterDelegate Filter) const;
    TArray<TSubclassOf<AActor>> GetLoadedItemList(EItemCategory Category) const;
    TArray<UItemID*> GetItemList(EItemCategory Category) const;
    int32 GetItemIndex(EItemCategory Category, UItemID* Item) const;
    TArray<UItemID*> GetAllItemsList() const;
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    void CheckForInventoryAchievements(UObject* WorldContextObject);
};
