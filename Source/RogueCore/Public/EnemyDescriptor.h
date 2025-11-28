#pragma once
#include "CoreMinimal.h"

#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "DeepPathFinderType.h"
#include "ECreatureSize.h"
#include "EEnemyDescriptorCheatClass.h"
#include "EEnemyDescriptorCheatTag.h"
#include "EEnemySignificance.h"
#include "EnemyDebris.h"
#include "ForbiddenData.h"
#include "SpawnRarityItem.h"
#include "Templates/SubclassOf.h"
#include "EnemyDescriptor.generated.h"

class AActor;
class APawn;
class UBiome;
class UCaveInfluencer;
class UCurveFloat;
class UDebrisPositioning;
class UEnemyDescriptor;
class UEnemyID;
UCLASS(Blueprintable)
class ROGUECORE_API UEnemyDescriptor : public UDataAsset {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEnemyID* EnemyID;
    
    TSoftClassPtr<APawn> EnemyClass;
    UCurveFloat* VeteranScaling;
    UEnemyDescriptor* VeteranClass;
    TMap<UBiome*, TSoftClassPtr<APawn>> BiomeEnemyClassOverrides;
    EEnemySignificance EnemySignificance;
    FVector SpawnOffset;
    bool UsesSpawnEffects;
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    ECreatureSize CreatureSize;
    bool UsePositioningInGameplay;
    UDebrisPositioning* PositioningAsset;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebrisPositioning* CustomPositioning;
    UCaveInfluencer* CaveInfluencer;
    int32 PlaceInGroupsOf;
    float PlaceInGroupRadius;
    TArray<FEnemyDebris> Debris;
    float InfluencerRange;
    TSubclassOf<AActor> PlacementCarver;
    DeepPathFinderType PathfinderType;
    bool SpawnAtUprightLocation;
    FGameplayTagQuery PlacementRoomQuery;
    TArray<FForbiddenData> ForbiddenPlacementIndices;
    float SpawnSpread;
    int32 IdealSpawnSize;
    bool CanBeUsedForConstantPressure;
    bool CanBeUsedInEncounters;
    float DifficultyRating;
    int32 MinSpawnCount;
    int32 MaxSpawnCount;
    float Rarity;
    float SpawnAmountModifier;
    int32 RequiredMainCampaignProgress;
    bool UsesSpawnRarityModifiers;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, EditFixedSize, meta=(AllowPrivateAccess=true))
    TArray<FSpawnRarityItem> SpawnRarityModifiers;
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemyDescriptorCheatClass CheatClass;
    EEnemyDescriptorCheatTag CheatTag;
    UEnemyDescriptor();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<APawn> GetEnemyClass(UBiome* Biome) const;
    UFUNCTION(BlueprintCallable)
    static TArray<UEnemyDescriptor*> FindTagsForCheatMenu(EEnemyDescriptorCheatClass NewCheatTag);
    static TArray<UEnemyDescriptor*> FindEnemiesWithClassWithoutTagForCheatMenu(EEnemyDescriptorCheatClass NewCheatClass, EEnemyDescriptorCheatTag removeTag);
    static TArray<UEnemyDescriptor*> FindDescriptorsForCheatMenu(EEnemyDescriptorCheatClass NewCheatClass);
    static TArray<UEnemyDescriptor*> FindAllDescriptorsForCheatMenu();
};
