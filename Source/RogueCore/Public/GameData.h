#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Object.h"
#include "GameplayTagContainer.h"
#include "AssetsToLoadSettings.h"
#include "EPerkName.h"
#include "GDAudio.h"
#include "GDCharacterRetirement.h"
#include "GDDamageClasses.h"
#include "GDDifficulty.h"
#include "GDElementTypes.h"
#include "GDGameStatsTracking.h"
#include "GDItemCategoryIDs.h"
#include "GDMilestones.h"
#include "GDMissionStats.h"
#include "GDResources.h"
#include "GDStats.h"
#include "GDTerrainTypes.h"
#include "GVisibilityGroups.h"
#include "PerkSettings.h"
#include "RetirementCostItem.h"
#include "Templates/SubclassOf.h"
#include "GameData.generated.h"

class APlayerCharacter;
class UAbilitySettings;
class UAccessCondition;
class UAchievementList;
class UAfflictionSettings;
class UAsyncManager;
class UBXESettings;
class UCharacterSettings;
class UDailyDealSettings;
class UDamageNumberSettings;
class UDamageSettings;
class UDanceSettings;
class UDifficultySetting;
class UDrinkSettings;
class UDynamicIconSettings;
class UEffectSettings;
class UEncounterSettings;
class UEnemySettings;
class UFSDEventCollection;
class UFSDTagSettings;
class UFSDTutorialSettings;
class UForginSettings;
class UGameActivitySettings;
class UGameAnimationSettings;
class UHUDVisibilityGroup;
class UInstancedNiagaraSettings;
class UIntelSettings;
class UInventoryList;
class UItemSettings;
class UItemSkinSettings;
class UKPISettings;
class UKeyBindingSettings;
class ULegacySettings;
class UMilestoneAsset;
class UMinersManual;
class UMissionStat;
class UPerkAsset;
class UPerkSettingsAsset;
class UPickaxeSettings;
class UPlanetZoneSetup;
class UPlayerCharacterID;
class UProceduralSettings;
class UPromotionRewardsSettings;
class URewardTreeSettings;
class USaveGameSettings;
class USchematicSettings;
class USeasonSettings;
class UShowroomSettings;
class USpawnSettings;
class USpecialEventSettings;
class UStageSettings;
class UStatusEffectSettings;
class UTerrainMaterialSettings;
class UTexture2D;
class UTreasureSettings;
class UUpgradeSettings;
class UVanitySettings;
class UVictoryPoseSettings;
UCLASS(Blueprintable)
class ROGUECORE_API UGameData : public UObject {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGVisibilityGroups VisibilityGroups;
    
    UPromotionRewardsSettings* PromotionRewardsSettings;
 
    UKPISettings* KPI_Settings;
    UPerkSettingsAsset* PerkSettings;
    UAbilitySettings* AbilitySettings;
    UFSDEventCollection* FsdEventsSettings;
    UGameActivitySettings* GameActivitySettings;
    UDanceSettings* DanceSettings;
    UGameAnimationSettings* AnimationSettings;
    UEnemySettings* EnemySettings;
    UDamageSettings* DamageSettings;
    UPlanetZoneSetup* ZoneSettings;
    UTreasureSettings* TreasureSettings;
    UDrinkSettings* DrinkSettings;
    UUpgradeSettings* UpgradeSettings;
    USpawnSettings* SpawnSettings;
    UVanitySettings* VanitySettings;
    UKeyBindingSettings* KeyBindingSettings;
    UBXESettings* BXESettings;
    UEncounterSettings* EncounterSettings;
    UForginSettings* ForgingSettings;
    USchematicSettings* SchematicSettings;
    UItemSkinSettings* SkinSettings;
    USpecialEventSettings* SpecialEventSettings;
    UProceduralSettings* ProceduralSettings;
    UPickaxeSettings* PickaxeSettings;
    UFSDTagSettings* TagSettings;
    UItemSettings* ItemSettings;
    UDynamicIconSettings* DynamicIconSettings;
    UShowroomSettings* ShowroomSettings;
    UVictoryPoseSettings* VictoryPoseSettings;
    UFSDTutorialSettings* TutorialSettings;
    ULegacySettings* LegacySettings;
    UEffectSettings* EffectSettings;
    UAfflictionSettings* AfflictionSettings;
    UDailyDealSettings* DailyDealSettings;
    UTerrainMaterialSettings* TerrainMaterialSettings;
    USaveGameSettings* SaveGameSettings;
    UDamageNumberSettings* DamageNumberSettings;
    UIntelSettings* IntelSettings;
    FGDItemCategoryIDs ItemCategoryIDs;
    TArray<UTexture2D*> LoadoutIconList;
    UMinersManual* MinersManual;
    FGDDamageClasses DamageClasses;
    FGDStats Stats;
    FGDResources Resources;
    FGDElementTypes ElementTypes;
    FGDTerrainTypes TerrainTypes;
    FGDGameStatsTracking GameStatsTracking;
    FGDAudio Audio;
    FGDDifficulty Difficulty;
    UStatusEffectSettings* StatusEffects;
    FGDCharacterRetirement Retirement;
    UCharacterSettings* CharacterSettings;
    UAchievementList* Achievements;
    UStageSettings* StageSettings;
    USeasonSettings* SeasonSettings;
    UInstancedNiagaraSettings* InstancedNiagaraSettings;
    URewardTreeSettings* RewardTreeSettings;
    UPlayerCharacterID* DefaultCharacterID;
    FGameplayTag XBoxExcludeRoomTag;
    FAssetsToLoadSettings AssetsToLoad;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FGuid, UAccessCondition*> AccessConditions;
    UGameData();
    UFUNCTION(BlueprintCallable)
    void LoadDefaultAssetsBlocking(UAsyncManager* AsyncManager);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCheatConsolesEnabled() const;
    TArray<UPlayerCharacterID*> GetRankedHeroIDs() const;
    FText GetPlayerRankName(int32 Rank) const;
    UPlayerCharacterID* GetPlayerCharacterID(const FGuid& ID) const;
    FPerkSettings GetPerkData() const;
    UPerkAsset* GetPerk(const EPerkName InPerkName) const;
    FGDMissionStats GetMissionStats() const;
    FGDMilestones GetMileStonesData() const;
    UInventoryList* GetInventoryList() const;
    UDifficultySetting* GetDifficultySetting(int32 Index) const;
    int32 GetDifficultyIndex(UDifficultySetting* NewDifficulty) const;
    UPlayerCharacterID* GetDefaultCharacterID() const;
    TSubclassOf<APlayerCharacter> GetDefaultCharacter() const;
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    FRetirementCostItem GetCharacterRetirementCost(UObject* WorldContext, UPlayerCharacterID* ID) const;
    TArray<UHUDVisibilityGroup*> GetAllVisibilityGroups() const;
    TArray<UMissionStat*> GetAllMissionStats() const;
    TArray<UMilestoneAsset*> GetAllMilestones() const;
    TArray<UMissionStat*> GetAllInfirmaryStats() const;
};
