#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CraftingCost.h"
#include "EItemUpgradeStatus.h"
#include "GearStatEntry.h"
#include "MasteryItem.h"
#include "Templates/SubclassOf.h"
#include "UpgradeTier.h"
#include "UpgradableGearComponent.generated.h"

class AActor;
class AFSDPlayerController;
class AFSDPlayerState;
class APlayerCharacter;
class UItemData;
class UItemID;
class UItemUpgrade;
class UObject;
class UPlayerCharacterID;
class UResourceData;
class UTexture2D;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UUpgradableGearComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemData* ItemData;
    
    UTexture2D* IconLine;
    UTexture2D* IconBG;
    UTexture2D* IconDetailed;
    TSoftObjectPtr<UTexture2D> PreviewImage;
    TSoftClassPtr<AActor> PreviewActor;
    FText Name;
    FText Category;
    FText Description;
    int32 CreditCost;
    TMap<UResourceData*, float> ResourceCost;
    int32 RequiredCharacterLevel;
    TArray<FMasteryItem> masteryLevels;
    UUpgradableGearComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    static void SetGearStatText(UPARAM(Ref) FGearStatEntry& Entry, FText Text);
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    bool PurchaseUpgrade(UItemID* ItemID, UItemUpgrade* upgrade, AFSDPlayerController* PlayerController, TSubclassOf<APlayerCharacter> previewedCharacter) const;
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool PurchaseItem(UObject* WorldContextObject, UItemID* ItemID);
    static bool PlayerOwnesUpgradeInAllTiers(TSubclassOf<AActor> itemClass, UObject* WorldContextObject);
    static void MirrorUpgradePreviewStatus(UPARAM(Ref) FGearStatEntry& From, UPARAM(Ref) FGearStatEntry& To);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsUpgradeEquipped(TSubclassOf<AActor> itemClass, UItemUpgrade* upgrade, AFSDPlayerState* Player);
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsTierUnLocked(UObject* WorldContextObject, TSubclassOf<AActor> itemClass, int32 tierIndex, UPlayerCharacterID* characterID);
    static bool IsItemUnlocked(UObject* WorldContextObject, UItemID* Item);
    static bool IsItemOwned(UObject* WorldContextObject, UItemID* Item);
    static bool IsItemEquipped(UObject* WorldContextObject, UItemID* ItemID);
    static int32 GetUpgradeTier(TSubclassOf<AActor> itemClass, UItemUpgrade* ItemUpgrade);
    FString GetSourceGearName() const;
    TMap<UResourceData*, float> GetResourceCost() const;
    int32 GetRequiredCharacterLevel() const;
    UTexture2D* GetPreviewImage() const;
    TSubclassOf<AActor> GetPreviewActorClass() const;
    static int32 GetMasteryProgress(UObject* WorldContextObject, UItemID* ItemID, int32& maxMastery);
    static TArray<FMasteryItem> GetMasteryLevels(UItemID* ItemID);
    static bool GetMasteryForLevel(const TArray<FMasteryItem>& NewMasteryLevels, int32 Level, FMasteryItem& outLevel);
    static TArray<FUpgradeTier> GetItemUpgradeTiers(TSubclassOf<AActor> itemClass);
    static EItemUpgradeStatus GetItemUpgradeStatus(UObject* WorldContextObject, TSubclassOf<AActor> itemClass, UItemUpgrade* ItemUpgrade, UPlayerCharacterID* characterID);
    static TArray<UItemUpgrade*> GetItemUpgradesFromSave(TSubclassOf<AActor> itemClass, TSubclassOf<UItemUpgrade> upgradeClass, AFSDPlayerState* Player, uint8 upgradeIndex);
    static TSubclassOf<AActor> GetItemPreviewClassFromActor(TSubclassOf<AActor> Actor);
    static TSubclassOf<AActor> GetItemPreviewClass(UItemID* ItemID);
    static bool GetItemMasteryForLevel(UItemID* ItemID, int32 Level, FMasteryItem& outLevel);
    UTexture2D* GetIconLine() const;
    UTexture2D* GetIconDetailed();
    UTexture2D* GetIconBG();
    static FText GetGearStatValue(UPARAM(Ref) FGearStatEntry& Entry);
    static TArray<FGearStatEntry> GetGearStats(AFSDPlayerState* PlayerState, TSubclassOf<AActor> ActorClass);
    static FString GetGearSourceName(UItemID* ItemID);
    FText GetGearName() const;
    FText GetGearDescription() const;
    FText GetGearCategory() const;
    static TArray<UItemUpgrade*> GetEquippedUpgrades(TSubclassOf<AActor> itemClass, AFSDPlayerState* Player);
    static UItemUpgrade* GetEquippedUpgradeAtTier(TSubclassOf<AActor> itemClass, int32 tierIndex, UPlayerCharacterID* characterID, AFSDPlayerState* Player);
    int32 GetCreditCost() const;
    TArray<FCraftingCost> GetCraftingCost() const;
    static int32 GetCharacterLevelRequiredForItem(UItemID* ItemID);
    TArray<UItemUpgrade*> GetAllUpgrades() const;
    static void ClearEquippedUpgrade(TSubclassOf<AActor> itemClass, int32 tierIndex, AFSDPlayerState* Player);
    static void CheckMasteryUnlocks(UItemID* ItemID, AFSDPlayerController* Player);
    static bool CanAffordUpgrade(UObject* WorldContextObject, UItemUpgrade* upgrade);
    static bool CanAffordItem(UObject* WorldContextObject, UItemID* ItemID);
};
