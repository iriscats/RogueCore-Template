#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "Engine/LatentActionManager.h"
#include "CarvedResource.h"
#include "CollectableSpawnableItem.h"
#include "DebrisCapsule.h"
#include "ECriticalItemPass.h"
#include "EDebrisItemPass.h"
#include "ESpawnSettings.h"
#include "EncounterSpecialItem.h"
#include "EncountersSpawnedDelegateDelegate.h"
#include "GemResourceAmount.h"
#include "GeneratedDebris.h"
#include "GeneratedInfluenceSets.h"
#include "GeneratedInstantCarvers.h"
#include "GeneratedTerrainActor.h"
#include "InfluenceMap.h"
#include "PathObstacle.h"
#include "RandRange.h"
#include "RoomNode.h"
#include "Templates/SubclassOf.h"
#include "TerrainPlacementDebugGroup.h"
#include "TunnelNode.h"
#include "ProceduralSetup.generated.h"

class ADebrisDataActor;
class ADeepCSGWorld;
class AFSDPlayerController;
class AProceduralSetup;
class ATunnelDecoration;
class UBiome;
class UCaveInfluencer;
class UConstructionSpawnerComponent;
class UDebrisBase;
class UFloodFillSettings;
class UMissionDNA;
class UNoisyPathfinderComponent;
class UObject;
class UPLSEncounterComponent;
class UProceduralObjectColliders;
class UProceduralResources;
class UProceduralTunnelComponent;
class UProceduralVeinsComponent;
class UResourceData;
class URoomGeneratorBase;
class USpecialEvent;
class UTunnelParameters;
UCLASS(Blueprintable)
class ROGUECORE_API AProceduralSetup : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShowItemNoisePattern;
    
    int32 Seed;
    bool UseRandomSeed;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRandomStream RandomStream;
    FRandomStream RandomStreamServer;
    FRandomStream RandomStreamAsync;
    FRandomStream RandomStreamAsyncServer;
    FEncountersSpawnedDelegate OnEncounterSpawnedEvent;
    TArray<FEncounterSpecialItem> SpecialEncountersToSpawn;
    USpecialEvent* ForcedMachineEvent;
    USpecialEvent* ForcedTreasure;
    USpecialEvent* ForcedOtherEvent;
    TSoftClassPtr<ADebrisDataActor> StageDebrisActor;
    TMap<TSubclassOf<AActor>, FGeneratedTerrainActor> SpawnedTerrainActors;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNoisyPathfinderComponent* NoisyPathfinder;
    UProceduralTunnelComponent* ProceduralTunnel;
    UPLSEncounterComponent* Encounters;
    UConstructionSpawnerComponent* ConstructionSpawnerComponent;
    UProceduralVeinsComponent* Veins;
    UProceduralResources* Resources;
    UProceduralObjectColliders* ObjectColliders;
    ADeepCSGWorld* CSGWorld;
    UFloodFillSettings* PathfinderNoise;
    TArray<FCarvedResource> CarvedResources;
    TSubclassOf<UMissionDNA> MissionDNA;
    TArray<FGemResourceAmount> GemResourcesToGenerate;
    TArray<FCollectableSpawnableItem> CollectablesToGenerate;
    ESpawnSettings SpawnSettings;
    bool CanSpawnSpecialEvents;
    bool ShouldCarveTunnels;
    TArray<FRoomNode> Rooms;
    TArray<FRoomNode> RoomsInitialState;
    TArray<int32> RoomsNonPostCarvedIndicies;
    TArray<FTunnelNode> tunnels;
    TArray<ATunnelDecoration*> SpawnedTunnelDecoration;
    FGeneratedInfluenceSets GeneratedInfluenceSets;
    FGeneratedInstantCarvers GeneratedInstantCarvers;
    FGeneratedDebris GeneratedDebris;
    UBiome* Biome;
    float missionLength;
    TArray<FPathObstacle> PathObstacles;
    FInfluenceMap InfluenceMap;
    TArray<UResourceData*> SpawnedResources;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    float CaveDepth;
    AActor* PostProcessActor;
    USpecialEvent* SpecialEvent;
    bool IsInitialized;
    int32 CurrentRoomPass;
    bool Pass1Completed;
    bool UsePerLevelCritterSpawning;
    FString LastCompletedPLSPass;
    FString CurrentAsyncTaskName;
    AProceduralSetup(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    bool ToggleTrackSpawnedTerrainActor(TSubclassOf<AActor> SubClass);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void StartMusicAndAmbient(int32 Music);
    void StartGenerationOnClient(AFSDPlayerController* client);
    UFUNCTION(BlueprintCallable, meta=(Latent, LatentInfo="LatentInfo"))
    void SpawnTunnelDecoration_Async(FLatentActionInfo LatentInfo);
    void SpawnTunnelDecoration();
    void SpawnSpecialEvents();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SpawnObjectiveEncounter();
    void SpawnObjectiveCriticalItems(const ECriticalItemPass& pass);
    void SpawnLevelDecoration_Async(FLatentActionInfo LatentInfo);
    void SpawnLevelDecoration();
    static void SpawnItems_Async(AProceduralSetup* setup, FLatentActionInfo LatentInfo);
    void SpawnItems();
    void SpawnEncounters();
    static void SpawnDebrisItems_Async(AProceduralSetup* setup, FLatentActionInfo LatentInfo, EDebrisItemPass pass, int32 Depth);
    void SpawnDebrisItems(EDebrisItemPass pass);
    void SpawnConstructions_Async(FLatentActionInfo LatentInfo);
    void SpawnConstructions();
    void SpawnConstructionRequiringActors_Async(FLatentActionInfo LatentInfo);
    void SpawnConstructionRequiringActors();
    void SetSeed(int32 NewSeed);
    void ResetData();
    void RemoveBLockedEntrances();
    void OnPLSDataRecieved();
    void OnObjectivesCompleted();
    void OnCarverDataRecieved(EDebrisItemPass pass);
    void LoadLevelDecoration(FLatentActionInfo LatentInfo, bool DoAsyncLoading);
    void LoadConstructionRequiringActors(FLatentActionInfo LatentInfo, bool DoAsyncLoading);
    void LoadConstructionGroups(FLatentActionInfo LatentInfo, bool DoAsyncLoading);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsGeneratedDataReady() const;
    bool IsCarverDataReady(EDebrisItemPass pass) const;
    void InitializeObjectives();
    TArray<FTerrainPlacementDebugGroup> GetTerrainPlacementDebug() const;
    int32 GetRoomIndexFromPosition(const FVector& position) const;
    UMissionDNA* GetMissionDNA() const;
    TMap<FString, float> GetGemsResourceAmounts() const;
    ADeepCSGWorld* GetCSGWorld() const;
    TMap<FString, float> GetCollectablesResourceAmounts() const;
    static void GenerateRoomsFromGraph_Async(AProceduralSetup* setup, FLatentActionInfo LatentInfo, int32 CarvePass);
    void GenerateRoomsFromGraph(int32 CarvePass);
    void GenerateLandscapeFromData(int32 NewSeed, const TArray<FRoomNode>& NewRooms, const TArray<FPathObstacle>& Obstacles);
    void GenerateLandscape();
    FVector FindLocationInDirection(FVector Origin, FVector Direction, float horizontalDeviation, float verticalDeviation, FRandRange Distance, float additionalDistance);
    void FindEntrancesForAllConnections();
    static void FillTunnels_Async(AProceduralSetup* setup, FLatentActionInfo LatentInfo);
    void FillTunnels();
    void DoneCarving();
    bool DoAsyncThreadGeneration() const;
    void CreateTunnelPaths();
    int32 CreateItemDepths();
    void CreateGeneratedInfluenceSet();
    int32 ConnectRoomIds(int32 fromID, int32 toID, bool hasDirt, UTunnelParameters* tunnelParameterOverride);
    void CommitCarving(bool finalCommit, bool generateMesh);
    void CarveWithGeneratedInstantCarvers();
    void CarveTunnels();
    void CarveDirt_Async(FLatentActionInfo LatentInfo);
    void CarveDirt();
    void BeginLiveGeneration();
    void BeginGenerating();
    int32 AddTunnelToRooms(UPARAM(Ref) FRoomNode& From, UPARAM(Ref) FRoomNode& To, bool hasDirt);
    int32 AddTunnelToRoomIds(int32 fromID, int32 toID, bool hasDirt);
    void AddRoomToInitialState(const FRoomNode& RoomNode);
    int32 AddRoom(FVector Location, bool CanHaveEnemies, URoomGeneratorBase* RoomGenerator, bool canBeRotated, FVector& outCenter, FRoomNode& outRoom, float ResourceMultiplier, const bool CanHaveExitElevator);
    void AddInfluenceToTunnelEntrances(UCaveInfluencer* Influencer, float Range);
    void AddImportantLocation(const FVector& Location, float Radius);
    void AddEnemyDebris();
    int32 AddDebrisCollider(const FDebrisCapsule& Capsule);
    void AddDebris(UDebrisBase* Debris, UObject* Influencer);
    void AddCaveInfluence(UCaveInfluencer* Influencer, const FVector& Location, float Range);
    int32 AddAirParticlesCollider(const FDebrisCapsule& Capsule);
};
