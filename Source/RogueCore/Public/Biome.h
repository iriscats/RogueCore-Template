#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataAsset.h"
#include "Runtime/Engine/Classes/Sound/ReverbSettings.h"
#include "BiomeEnemyEntry.h"
#include "BiomeNoiseItem.h"
#include "HeatSource.h"
#include "LoadingScreenInfo.h"
#include "RandRange.h"
#include "ResourceSpawner.h"
#include "Templates/SubclassOf.h"
#include "Biome.generated.h"

class AActor;
class ADebrisDataActor;
class UCaveScriptComponent;
class UCritterDescriptor;
class UDebrisSet;
class UDetailNoise;
class UEnemyDescriptor;
class UFXSystemAsset;
class UFileMediaSource;
class UFloodFillSettings;
class UMaterialInstance;
class UMissionStat;
class UObject;
class UPillarSettings;
class UReverbEffect;
class USoundCue;
class UTerrainMaterial;
class UTexture2D;
class UTunnelSetting;
class UUserWidget;
UCLASS(Blueprintable)
class ROGUECORE_API UBiome : public UDataAsset {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText BiomeName;
    
    FText BiomeShortName;
    FText BiomeDescription;
    FColor BiomeColor;
    int32 BiomeIndex;
    FString BiomeAnalyticsIndex;
    bool IsTutorialBiome;
    TSoftObjectPtr<UFileMediaSource> BiomeMovie;
    TSoftObjectPtr<UTexture2D> BiomePicture;
    TSoftObjectPtr<UTexture2D> BiomeIconSimple;
    TSoftObjectPtr<UTexture2D> BiomeIcon;
    TSoftObjectPtr<UTexture2D> BiomeLargeImage;
    TSoftObjectPtr<UTexture2D> BiomeWorldMap;
    TSoftObjectPtr<UTexture2D> BiomeMissionBar;
    TSoftClassPtr<UUserWidget> BiomeMapWidget;
    FHeatSource BiomeHeatSource;
    FRandRange DepthRange;
    TSoftObjectPtr<UFXSystemAsset> AtmosphericParticles;
    TArray<TSoftClassPtr<UCaveScriptComponent>> CaveScriptComponents;
    float ExtraCaveSize;
    TArray<UDebrisSet*> Debris;
    TSoftClassPtr<ADebrisDataActor> DebrisActor;
    TSoftClassPtr<AActor> PostProcessActorClass;
    UTerrainMaterial* RockMaterial;
    UTerrainMaterial* DirtMaterial;
    UTerrainMaterial* BurnedMaterialOverride;
    TArray<TSoftObjectPtr<UMaterialInstance>> FlavorMaterials;
    TArray<FBiomeNoiseItem> RoomNoises;
    UMissionStat* MissionCompleted;
    UFloodFillSettings* CeilingNoise;
    UDetailNoise* CeilingDetailNoise;
    UFloodFillSettings* WallNoise;
    UDetailNoise* WallDetailNoise;
    UFloodFillSettings* FloorNoise;
    UDetailNoise* FloorDetailNoise;
    UFloodFillSettings* PillarNoise;
    UDetailNoise* PillarDetailNoise;
    UPillarSettings* PillarSettings;
    TArray<UTunnelSetting*> TunnelSettings;
    UFloodFillSettings* TunnelCeilingNoise;
    UFloodFillSettings* TunnelWallNoise;
    UFloodFillSettings* TunnelFloorNoise;
    TArray<FResourceSpawner> Resources;
    TArray<FBiomeEnemyEntry> Enemies;
    TArray<UEnemyDescriptor*> BannedEnemies;
    TArray<UEnemyDescriptor*> StationaryEnemies;
    TArray<UCritterDescriptor*> Critters;
    TSoftObjectPtr<USoundCue> AmbientSounds;
    bool Use3DAmbient;
    FReverbSettings ReverbSettings;
    float SmallCaveReverbVolume;
    UReverbEffect* SmallCaveReverb;
    float MediumCaveReverbVolume;
    UReverbEffect* MediumCaveReverb;
    float LargeCaveReverbVolume;
    UReverbEffect* LargeCaveReverb;
    TSoftObjectPtr<USoundCue> TunnelAmbience;
    FLoadingScreenInfo BiomeLoaderLevelSequence;
    FString BiomeLoaderLevelName;
    TArray<FText> Quotes;
    float PlanetZoneSelectionWeight;
    float FloorAndWallSmoothingDistance;
    UBiome();
    UFUNCTION(BlueprintCallable, BlueprintPure=false, meta=(WorldContext="WorldContext"))
    void StartPreload(UObject* WorldContext) const;
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTerrainMaterial* GetRockMaterial() const;
    TSoftClassPtr<AActor> GetPostProcessActorClass_Soft() const;
    UMaterialInstance* GetFlavorMaterial() const;
    UTerrainMaterial* GetDirtMaterial() const;
    TSoftClassPtr<ADebrisDataActor> GetDebrisActorSoftClass();
    UTexture2D* GetBiomeWorldMap() const;
    UTexture2D* GetBiomePicture() const;
    FText GetBiomeName() const;
    UTexture2D* GetBiomeMissionBar() const;
    TSubclassOf<UUserWidget> GetBiomeMapWidget() const;
    TArray<FSoftObjectPath> GetBiomeMapAssetList() const;
    UTexture2D* GetBiomeLargeImage() const;
    int32 GetBiomeIndex() const;
    UTexture2D* GetBiomeIconSimple() const;
    UTexture2D* GetBiomeIcon() const;
    FString GetBiomeAnalyticsIndex() const;
    UFXSystemAsset* GetAtmosphericParticles() const;
    USoundCue* GetAmbientSounds() const;
};
