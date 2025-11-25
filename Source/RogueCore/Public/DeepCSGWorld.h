#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "Engine/LatentActionManager.h"
#include "VisualLogger/VisualLoggerDebugSnapshotInterface.h"
#include "CarveOptionsCellSize.h"
#include "CarveSplineSegment.h"
#include "ECarveFilterType.h"
#include "EPreciousMaterialOptions.h"
#include "EncodedChunkId.h"
#include "CSGBuildOperationData.h"
#include "CSGRaycastHitInfo.h"
#include "CarveWithColliderOperationData.h"
#include "CarveWithSTLMeshOperationData.h"
#include "DebrisWhenCarving.h"
#include "DrillOperationData.h"
#include "ELandscapeCellFilter.h"
#include "ESpecialDebrisType.h"
#include "FSDTerrainGenerationStats.h"
#include "GrenadeExplodeOperationData.h"
#include "MeltOperationData.h"
#include "PickaxeDigOperationData.h"
#include "RemoveFloatingIslandOperationData.h"
#include "RuntimeSpawnedDebris.h"
#include "SplineSegmentCarveOperationData.h"
#include "Templates/SubclassOf.h"
#include "TerrainBaseDoneDelegate.h"
#include "TerrainLateJoinData.h"
#include "TerrainSpawnDebrisOperationData.h"
#include "DeepCSGWorld.generated.h"

class ACSGBuilder;
class ADebrisDataActor;
class ADeepCSGWorld;
class AProceduralSetup;
class UAsyncPathRequests;
class UDebrisBase;
class UDebrisInstances;
class UDebrisMesh;
class UDebrisSet;
class UMaterialInterface;
class UObject;
class UPrimitiveComponent;
class USTLMeshCarver;
class UStaticMesh;
class UStaticMeshCarver;
class UTerrainMaterial;
class UTerrainMaterialsCollection;
class UTerrainType;
UCLASS(Blueprintable)
class ROGUECORE_API ADeepCSGWorld : public AActor, public IVisualLoggerDebugSnapshotInterface {
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTerrainMaterial* DebugCarveInsideTerrainMaterial;

    UTerrainMaterial* DebugCarveOutsizeTerrainMaterial;
    UTerrainMaterial* DebugCarveEdgeTerrainMaterial;
    UTerrainMaterial* GoldTerrainMaterial;
    UTerrainMaterial* MOMTerrrainMaterial;
    UTerrainMaterial* NitraTerrrainMaterial;
    UTerrainMaterial* EmptyTerrainMaterial;
    UTerrainMaterial* DefaultBurntTerrainMaterial;
    UTerrainMaterial* DefaultHardRockMaterial;
    UTerrainMaterial* DefaultBedRockMaterial;
    UTerrainType* GoldTerrainType;
    UTerrainType* MOMTerrainType;
    UTerrainType* RockTerrainType;
    UTerrainType* CrystalTerrainType;
    UTerrainType* EmptyTerrainType;
    UTerrainType* DirtTerrainType;
    UTerrainType* DefaultBurntTerrainType;
    UTerrainMaterialsCollection* TerrainMaterials;
    TArray<UDebrisSet*> StandardDebrisSets;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UDebrisBase*> DebrisLevelGenerationCarved;
    TArray<UDebrisBase*> DebrisPreLargeCarved;
    TArray<UDebrisBase*> DebrisLargeCarved;
    TArray<UDebrisBase*> DebrisSmallCarved;
    TArray<UDebrisBase*> DebrisMeshes;
    UMaterialInterface* DefaultScannerMaterial;
    UMaterialInterface* DefaultConstructionScannerMaterial;
    TSubclassOf<ACSGBuilder> TestLevelCarver;
    FBox TestLevelCarverBoundingBox;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAsyncPathRequests* AsyncPathRequests;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTerrainBaseDone OnBaseLayerCommitDone;
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UObject>> TerrainListeners;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UDebrisInstances*> DebrisInstanceList;
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UPrimitiveComponent>> ShowAlwaysScannerComponents;

    // Blueprint Implementable Events
    UFUNCTION(BlueprintImplementableEvent)
    void TerrainOp_RemoveFloating(const FRemoveFloatingIslandOperationData& Data);
    UFUNCTION(BlueprintImplementableEvent)
    void TerrainOp_PickAxe(const FPickaxeDigOperationData& Data);
    UFUNCTION(BlueprintImplementableEvent)
    void TerrainOp_Melt(const FMeltOperationData& Data);
    UFUNCTION(BlueprintImplementableEvent)
    void TerrainOp_Explode(const FGrenadeExplodeOperationData& Data);
    UFUNCTION(BlueprintImplementableEvent)
    void TerrainOp_Drill(const FDrillOperationData& Data);
    UFUNCTION(BlueprintImplementableEvent)
    void TerrainOp_CarveSTLMesh(const FCarveWithSTLMeshOperationData& Data);
    UFUNCTION(BlueprintImplementableEvent)
    void TerrainOp_CarveSplineSegment(const FSplineSegmentCarveOperationData& Data);
    UFUNCTION(BlueprintImplementableEvent)
    void TerrainOp_CarveCSG(const FCSGBuildOperationData& Data);
    UFUNCTION(BlueprintImplementableEvent)
    void TerrainOp_CarveCollider(const FCarveWithColliderOperationData& Data);
    UFUNCTION(BlueprintImplementableEvent)
    void RemoveDebrisInstance_TerrainOp2(int32 instance, int32 Component);
 
    ADebrisDataActor* DebrisActorInstance;
    int32 DebrisActorIndex;
    AProceduralSetup* ProceduralSetup;
    TArray<UObject*> TerrainMaterialAssets;
    FTerrainBaseDone OnBaseLayerFinalCommitDone;
    TArray<AActor*> TerrainAttachedActors;
    TArray<UDebrisBase*> RegisteredDebrisList;
    TArray<FDebrisWhenCarving> DebrisWhenCarvingList;
    TArray<FRuntimeSpawnedDebris> RuntimeSpawnedDebris;
    TArray<TWeakObjectPtr<UPrimitiveComponent>> FogOfWarScannerComponents;
    TArray<UDebrisBase*> DebrisHandles;
    FTerrainLateJoinData LateJoinData;
    TArray<FEncodedChunkId> VisibleChunks;
    ADeepCSGWorld(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void UnRegisterScannerComponent(UPrimitiveComponent* Component);
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void TerrainOp_SpawnDebris(const FTerrainSpawnDebrisOperationData& Data);
    void TerrainMaterialDataLoaded();
    void SpawnDebris(UDebrisMesh* Debris, const FVector& Pos, float Radius);
    void SetVisibleToScanner(const FVector& Center, const FVector& Range);
    void SetRockMaterialForTest(UTerrainMaterial* Material);
    void SelectDebrisSettings();
    void ResetEntireWorld();
    void RemoveDebrisInSphere(const FVector& position, float Radius, bool onlyFragile, bool alsoDurable, ESpecialDebrisType onlyType);
    void RegisterScannerComponent(UPrimitiveComponent* Component, bool useFogOfWar);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool Raycast(FVector Start, FVector Direction, float MaxDistance, FCSGRaycastHitInfo& HitInfo, ELandscapeCellFilter Filter) const;
    bool Linecast(FVector Start, FVector End, FCSGRaycastHitInfo& HitInfo, ELandscapeCellFilter Filter) const;
    bool IsPositionVisibleToScanner(const FVector& Pos) const;
    bool IsPointInsideTerrain(const FVector& Pos) const;
    bool IsComponentRegisteredWithScanner(UPrimitiveComponent* Component);
    bool InitialGenerationDone() const;
    bool HasUnfinishedRuntimeOperations() const;
    int32 GetTerrainHash();
    static int32 GetShadowQuality();
    FFSDTerrainGenerationStats GetGenerationStats(bool detailed);
    ADebrisDataActor* GetDebrisDataActor() const;
    void GetAllTerrainActorsAroundPoint(const FVector& Center, const FVector& Range, TArray<AActor*>& TerrainActors);
    void GenerateAllMeshes();
    void FinishGeneration_Blocking();
    float FindTotalVolumeOfMaterialInWorld(UTerrainMaterial* Material);
    UFUNCTION(BlueprintCallable, meta=(Latent, LatentInfo="LatentInfo"))
    static void CarveWithSTLMeshUsingTransform_Wait(ADeepCSGWorld* CSGWorld, USTLMeshCarver* MeshCarver, UTerrainMaterial* Material, ECarveFilterType CarveFilter, const FTransform& Transform, EPreciousMaterialOptions Precious, FLatentActionInfo LatentInfo);
    void CarveWithSTLMeshUsingTransform(USTLMeshCarver* MeshCarver, UTerrainMaterial* Material, ECarveFilterType CarveFilter, const FTransform& Transform, EPreciousMaterialOptions Precious);
    static void CarveWithSTLMesh_Wait(ADeepCSGWorld* CSGWorld, USTLMeshCarver* MeshCarver, UTerrainMaterial* Material, ECarveFilterType CarveFilter, FVector Pos, FQuat Orientation, FVector Scale, EPreciousMaterialOptions Precious, FLatentActionInfo LatentInfo);
    void CarveWithSTLMesh(USTLMeshCarver* MeshCarver, UTerrainMaterial* Material, ECarveFilterType CarveFilter, FVector Pos, FQuat Orientation, FVector Scale, EPreciousMaterialOptions Precious);
    static void CarveWithStaticMeshUsingTransform_Wait(ADeepCSGWorld* CSGWorld, UStaticMeshCarver* MeshCarver, UTerrainMaterial* Material, ECarveFilterType CarveFilter, const FTransform& Transform, EPreciousMaterialOptions Precious, FLatentActionInfo LatentInfo);
    void CarveWithStaticMeshUsingTransform(UStaticMeshCarver* MeshCarver, UTerrainMaterial* Material, ECarveFilterType CarveFilter, const FTransform& Transform, EPreciousMaterialOptions Precious);
    void CarveWithStaticMesh(UStaticMeshCarver* MeshCarver, UTerrainMaterial* Material, ECarveFilterType CarveFilter, FVector Pos, FQuat Orientation, FVector Scale, EPreciousMaterialOptions Precious);
    void CarveWithSplineSegments(const TArray<FCarveSplineSegment>& Segments, UTerrainMaterial* Material, float Noise, ECarveFilterType CarveFilter, EPreciousMaterialOptions Precious);
    void CarveWithSplineSegment(const FVector& SplineStart, const FVector& SplineStartTangent, const FVector& SplineEnd, const FVector& SplineEndTangent, float Radius, float Noise, UTerrainMaterial* Material, ECarveFilterType CarveFilter, EPreciousMaterialOptions Precious);
    static void CarveWithMeshUsingTransform_Wait(ADeepCSGWorld* CSGWorld, UStaticMesh* StaticMesh, UTerrainMaterial* Material, ECarveFilterType CarveFilter, const FTransform& Transform, float ExpensiveNoise, EPreciousMaterialOptions Precious, FLatentActionInfo LatentInfo);
    void CarveWithMeshUsingTransform(UStaticMesh* StaticMesh, UTerrainMaterial* Material, ECarveFilterType CarveFilter, const FTransform& Transform, float ExpensiveNoise, EPreciousMaterialOptions Precious, CarveOptionsCellSize CarverSize, bool anchorCenterPosition);
    static void CarveWithMesh_Wait(ADeepCSGWorld* CSGWorld, UStaticMesh* StaticMesh, UTerrainMaterial* Material, ECarveFilterType CarveFilter, FVector Pos, FQuat Orientation, FVector Scale, FLatentActionInfo LatentInfo);
    void CarveWithMesh(UStaticMesh* StaticMesh, UTerrainMaterial* Material, ECarveFilterType CarveFilter, FVector Pos, FQuat Orientation, FVector Scale, EPreciousMaterialOptions Precious);
    void CarveWithCSGBuild(TSubclassOf<ACSGBuilder> CSGModel, const FTransform& Transform);
    float CalcApproximateTerrainDensity(FVector Pos, float Radius);
    UTerrainMaterial* BPGetTerrainMaterial(int32 Handle) const;
    void BaseLayerCommitFinal(bool blocking);
    void BaseLayerCommit(bool blocking, bool scheduleTesselation);
    void AttachActorToTerrain(AActor* Actor, FVector Pos);
    void ApplyBaseDebrisCarvers(const TArray<UDebrisBase*>& Carvers);
    // Fix for true pure virtual functions not being implemented
};
