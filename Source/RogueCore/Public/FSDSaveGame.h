#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/SaveGame.h"
#include "AchievementSave.h"
#include "BXESave.h"
#include "CampaignSave.h"
#include "CharacterPerksSave.h"
#include "CharacterSave.h"
#include "ConsoleOptionsInSaveGame.h"
#include "DrinkSave.h"
#include "EFSDFaction.h"
#include "EItemCategory.h"
#include "ESonyControllerLightMode.h"
#include "ESonyControllerMotionMapping.h"
#include "ESonyInputSettingsBools.h"
#include "ESonyInputSettingsFloats.h"
#include "EventRewardSave.h"
#include "FSDEventRewardsSave.h"
#include "ForgingSave.h"
#include "GDKWinOptionsInSaveGame.h"
#include "GameDLCSave.h"
#include "ItemNotificationInfo.h"
#include "ItemUINotifications.h"
#include "JettyBootsSave.h"
#include "MilestoneSave.h"
#include "MissionStatSave.h"
#include "OptionsInSaveGame.h"
#include "PerkClaimsSave.h"
#include "PromotionRewardsSave.h"
#include "ResourcesSave.h"
#include "SchematicSave.h"
#include "SeasonSave.h"
#include "SkinList.h"
#include "SonyInputSettings.h"
#include "Templates/SubclassOf.h"
#include "UpgradeLoadout.h"
#include "VanityMasteryResult.h"
#include "VanityMasterySave.h"
#include "WatchedTutorial.h"
#include "FSDSaveGame.generated.h"

class AActor;
class APlayerCharacter;
class UBioBoosterDeck;
class UFSDGameInstance;
class UFSDSaveGame;
class UItemID;
class UItemSkin;
class UObject;
class UPerkAsset;
class UPlayerCharacterID;
class UResourceData;
UCLASS(Blueprintable)
class ROGUECORE_API UFSDSaveGame : public USaveGame {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTutorialsResetDelegate);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSkinSignature, UItemSkin*, Skin, UItemID*, ItemID);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FRetirementSignature, TSubclassOf<APlayerCharacter>, CharacterClass, int32, RetirementCount);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FResourceAmountChangedDelegate, const UResourceData*, Resource, float, CurrentAmount);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPlayerProgressChangedSignature, int32, Rank, int32, Stars);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPersonalMatricsChangedSignature, bool, AllowPersonalMetrics);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPerkPointsChangedSignature, int32, PerkPoints, int32, change);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FItemUnlockedDelegate);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FItemUINotificationDelegate);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FForgingXPDelegate, float, XP);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCreditsChangedSignature, int32, Credits);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCraftingMasteryChanged, FVanityMasteryResult, Result);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCharacterSignature, TSubclassOf<APlayerCharacter>, CharacterClass);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FCharacterProgressChangedSignature, TSubclassOf<APlayerCharacter>, CharacterClass, int32, Level, float, Progress);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBXESaveChanged, const FBXESave&, InSave);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAnonymousMatricsChangedSignature, bool, AllowAnonymousMetrics);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FBXESaveChanged OnBXESaveChanged;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBXESave BXESave;
    FCreditsChangedSignature OnCreditsChanged;
    FCharacterProgressChangedSignature OnCharacterSaveChanged;
    FCharacterSignature OnCharacterCanRetire;
    FRetirementSignature OnCharacterRetired;
    FPlayerProgressChangedSignature OnPlayerProgressChanged;
    FTutorialsResetDelegate OnTutorialsReset;
    FPersonalMatricsChangedSignature OnPersonalMetricsChanged;
    FAnonymousMatricsChangedSignature OnAnonymousMetricsChanged;
    FItemUnlockedDelegate OnItemUnlocked;
    FItemUnlockedDelegate OnItemPurchased;
    FItemUINotificationDelegate OnItemUINotificationChange;
    int32 VersionNumber;
    bool bMilestoneResetShown;
    bool bYearTwoGiftClaimed;
    bool bSeenClosedAlphaVideo;
    FForgingXPDelegate OnForgingXPChanged;
    FResourceAmountChangedDelegate OnResourceAmountChanged;
    FSkinSignature OnSkinUnlocked;
    FDateTime SaveSlotTimeStamp;
    FPerkPointsChangedSignature OnPerkPointsChanged;
    FMissionStatSave MissionStatsSave;
    FMilestoneSave Milestones;
    FPerkClaimsSave EnhancementPerks;
    FCharacterPerksSave EquippedEnhancementPerks;
    FAchievementSave AchievementSave;
    TArray<FCharacterPerksSave> EnhancementPerkLoadouts;
    FVanityMasterySave VanityMasterySave;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCraftingMasteryChanged OnVanityMasteryChanged;
    FJettyBootsSave JettyBootsSave;
    FSchematicSave SchematicSave;
    FPromotionRewardsSave PromotionRewardsSave;
    FFSDEventRewardsSave FSDEventRewardsSave;
    FSeasonSave SeasonSave;
    FGameDLCSave GameDLCSave;
    int32 SaveCreatedInPatch;
    FString AnonymousID;
    int32 PerkPoints;
    bool HasRecievedDiscordReward;
    EFSDFaction Faction;
    TArray<FGuid> UnLockedComplexities;
    TArray<FGuid> UnLockedDurations;
    TArray<FGuid> UnLockedPlanetZones;
    FCampaignSave CampaignSave;
    TArray<FCharacterSave> CharacterSaves;
    int32 Credits;
    int32 ReclaimerPoints;
    int32 ReclaimerPointLevel;
    int32 CurrentReclaimerPoints;
    int32 LastBoughtDailyDealSeed;
    FForgingSave Forging;
    FDrinkSave Drinks;
    TArray<FUpgradeLoadout> ItemUpgradeLoadouts;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIgnoreRandomLoadout;
    TArray<FGuid> PurchasedItemUpgrades;
    TArray<FGuid> UnlockedItems;
    TArray<FGuid> OwnedItems;
    TMap<FGuid, int32> EnemiesKilled;
    TMap<FGuid, FItemNotificationInfo> ItemsWithNotification;
    TMap<FGuid, FSkinList> UnlockedItemSkins;
    TSet<FGuid> UnlockedPickaxeParts;
    TArray<FGuid> UnLockedVanityItemIDs;
    TArray<FGuid> HiddenUICategories;
    int32 LastCollectedCommunityRewardPeriodID;
    TSet<FGuid> MinersManualKnownObjects;
    TSet<FGuid> UnlockedAccessConditions;
    FEventRewardSave EventRewardSave;
    FItemUINotifications ItemUINotifications;
    FString RejoinSessionId;
    bool FirstRejoinAttempt;
    bool bHasOpenedDeepDiveTerminal;
    FResourcesSave Resources;
    bool FirstSession;
    TArray<FWatchedTutorial> WatchedTutorials;
    FConsoleOptionsInSaveGame ConsoleOptions;
    FGDKWinOptionsInSaveGame WinGDKOptions;
    FOptionsInSaveGame WindowsOptions;
    bool HasCompletedTutorial;
    bool HasPlayedTutorial;
    bool ShowHowToRestartTutorialPrompt;
    bool HasPlayedIntroMessage;
    bool HasSentSteamInfo;
    bool HasClaimedSteamGroupLoot;
    bool IsBoscoAllowed;
    bool HasJoinedXboxClub;
    bool HasSeenAnalyticsPopUp;
    bool AllowAnalyticsTracking;
    bool AllowPersonalAnalyticsTracking;
    int32 Index;
    FString Name;
    float TotalPlayTimeSeconds;
    TMap<FGuid, int32> SelectedLoadout;
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint32 userIdx;
    uint32 CurrLoadoutIdx;
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 SaveToDiskCounter;
    uint32 BackupSaveIndex;
    uint32 ExternalBackupSaveIndex;
    int32 NumberOfGamesPlayed;
    UPlayerCharacterID* LastPlayedCharacter;
    bool ShowInfoScreen;
    FString LastShownVersion;
    FSonyInputSettings SonyInputSettings;
    UFSDGameInstance* FSDGameInstance;
    UFSDSaveGame();
    UFUNCTION(BlueprintCallable)
    bool TrySellResource(UResourceData* Resource, int32 amount, int32& Price);
    bool TryDeductResources(const TMap<UResourceData*, int32>& NewResources);
    bool TryDeductReclaimerPoints(int32 amount);
    bool TryDeductCredits(int32 amount);
    bool TryBuyResource(UResourceData* Resource, int32 amount, int32& Price);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ShouldDisplayFirstSchematicMessage() const;
    void SetSonyInputSettingMotionXMapping(ESonyControllerMotionMapping NewValue);
    void SetSonyInputSettingLightMode(ESonyControllerLightMode NewValue);
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void SetSonyInputSettingFloat(UObject* WorldContext, ESonyInputSettingsFloats Setting, float NewValue);
    void SetSonyInputSettingBool(ESonyInputSettingsBools Setting, bool NewValue);
    bool SetPersonalAnalytics(bool State);
    void SetIndexAndName(int32 NewIndex, const FString& NewName);
    void SetIgnoreRandomLoadout(bool inIgnoreRandomLoadout);
    void SetHasSentSteamInfo();
    void SetHasJoinedXboxClub();
    void SetHasClaimSteamGroupLoot();
    void SetFaction(EFSDFaction newFaction, bool Reasign);
    void SetEquippedItemID(EItemCategory Category, UPlayerCharacterID* PlayerId, UItemID* Item);
    void SetEquippedItem(EItemCategory Category, UPlayerCharacterID* PlayerId, TSubclassOf<AActor> Item);
    void SetDiscordReward(bool State);
    void SetCurrentReclaimerPoints(int32 amount);
    void SetCharacterLoadout(UPlayerCharacterID* characterID, int32 loadoutNumber);
    void SetBoscoAllowed(bool aIsBoscoAllowed);
    void SetBioBoosterDecks(UPlayerCharacterID* characterID, const TArray<UBioBoosterDeck*>& InBoosterDecks);
    bool SetAnonymousAnalytics(bool State);
    void SaveToDisk();
    static bool SaveSlotToDisk(UFSDSaveGame* SaveSlot, const FString& slotName, int32 NewUserIdx);
    int32 RetireCharacter(UPlayerCharacterID* characterID);
    void ResetTutorials();
    void ResetSonyTouchSettings();
    void ResetSonyMotionSettings();
    void ResetSonyDualSenseSettings();
    void ResetRejoinSessionId();
    void RejoinAttempted();
    void RefreshLoadoutFromCharacter(UPlayerCharacterID* characterID);
    bool RecievedDiscordReward();
    FString PromotedClassesString();
    void MarkRetirementRewardScreenSeen(UPlayerCharacterID* characterID);
    void MarkFirstSchematicMessageSeen();
    void LevelUpCharacter(UObject* WorldContext, UPlayerCharacterID* characterID);
    bool IsObsolete() const;
    bool IsInMinersManual(FGuid ObjectId) const;
    bool IsFirstRejoinAttempt();
    bool HasSeenRetirementRewardScreen() const;
    bool HasReclaimerPoints(int32 amount) const;
    bool HasCredits(int32 amount) const;
    bool HasCharacterRetired(UPlayerCharacterID* characterID) const;
    bool HasCharacterCompletedRetirementCampaign(UPlayerCharacterID* characterID) const;
    static bool HasBackupWithMoreProgress(UFSDGameInstance* GameInstance);
    bool HasAnyCharacterRetired() const;
    int32 GetTotalGamesPlayed();
    int32 GetTotalCharacterXP() const;
    ESonyControllerMotionMapping GetSonyInputSettingMotionXMapping() const;
    ESonyControllerLightMode GetSonyInputSettingLightMode() const;
    float GetSonyInputSettingFloat(ESonyInputSettingsFloats Setting) const;
    bool GetSonyInputSettingBool(ESonyInputSettingsBools Setting) const;
    FDateTime GetSlotTimeStamp() const;
    FString GetSlotLoadedFrom() const;
    int32 GetSelectedLoadoutIndex(UPlayerCharacterID* characterID) const;
    static FString GetSaveSlotName(int32 NewUserIdx);
    int32 GetResourceSellingPrice(UResourceData* Resource, int32 amount) const;
    int32 GetResourceBuyingPrice(UResourceData* Resource, int32 amount) const;
    float GetResourceAmount(const UResourceData* Resource) const;
    int32 GetRequiredXPForLevel(int32 Level) const;
    FString GetRejoinSessionId();
    int32 GetReclaimerPoints() const;
    int32 GetReclaimerPointLevel() const;
    int32 GetPurchasableItemCount() const;
    int32 GetPlayerRetirementRank() const;
    int32 GetPlayerRank() const;
    int32 GetPerkPoints() const;
    FString GetName();
    static int32 GetMaxSaveSlots();
    static int32 GetMainSaves(UFSDGameInstance* GameInstance, TArray<UFSDSaveGame*>& outMainSaves);
    int32 GetIndex();
    bool GetHasSentSteamInfo();
    bool GetHasClaimedSteamGroupLoot();
    EFSDFaction GetFaction();
    UItemID* GetEquippedItemID(EItemCategory Category, UPlayerCharacterID* PlayerId) const;
    TSubclassOf<AActor> GetEquippedItem(EItemCategory Category, UPlayerCharacterID* PlayerId) const;
    int32 GetCurrentReclaimerPoints() const;
    int32 GetCredits() const;
    int32 GetClassXP(UPlayerCharacterID* characterID) const;
    int32 GetClassLevel(UPlayerCharacterID* characterID) const;
    int32 GetCharacterRetirementCount(const FGuid& PlayerId) const;
    bool GetBoscoAllowed() const;
    TArray<UBioBoosterDeck*> GetBioBoosterDecks(UPlayerCharacterID* characterID) const;
    static int32 GetAvailableUserSlotIndex(UFSDGameInstance* GameInstance);
    static TArray<UFSDSaveGame*> GetAllSavesFromDisk(UFSDGameInstance* GameInstance);
    static void FixNamingOfMainSave(UFSDSaveGame* mainsave);
    static bool DeleteFromDisk(UFSDGameInstance* GameInstance, const FString& slotName, int32 NewUserIdx);
    bool DeductPerkPoints(int32 amount);
    void ClaimEnhancementPerk(UPerkAsset* PerkAsset);
    void CheckPromotionAchievementProgress(UObject* WorldContext, bool IsRetroactive);
    bool CanAfford(const TMap<UResourceData*, int32>& NewResources) const;
    int32 AddReclaimerPoints(int32 amount);
    void AddPerkPoints(int32 amount);
    void AddGamePlayed();
    int32 AddCredits(int32 amount);
    int32 AddClassXP(UObject* WorldContext, UPlayerCharacterID* characterID, int32 XP);
};
