#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "Curves/CurveFloat.h"
#include "DropInfo.h"
#include "Templates/SubclassOf.h"
#include "PlagueMeteor.generated.h"

class AImpactIndicator;
class AProceduralSetup;
class ARockCrackerPod;
class UDamageComponent;
class UDebrisPositioning;
class USceneComponent;
class UStaticMesh;
class UStaticMeshComponent;
class UTerrainPlacementComponent;
UCLASS(Blueprintable, NoExport)
class ROGUECORE_API APlagueMeteor : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))

    AImpactIndicator* DropZoneIndicator;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))

    TArray<ARockCrackerPod*> SpawnedPods;

    APlagueMeteor(const FObjectInitializer& ObjectInitializer);



public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    UStaticMeshComponent* MeteorMesh;
    UTerrainPlacementComponent* terrainPlacement;
    UDamageComponent* ImpactDamage;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ManuallyTargeted;
protected:
    TArray<UStaticMesh*> Stages;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_CrackStage, meta=(AllowPrivateAccess=true))
    int32 CrackStage;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_DropInfo, meta=(AllowPrivateAccess=true))
    FDropInfo DropInfo;
    TSubclassOf<AImpactIndicator> DropzoneIndicatorClass;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AImpactIndicator* DropZoneIndicator;
    UDebrisPositioning* Positioning;
    FVector DropDirection;
    float IndicatorTime;
    float VisualsTime;
    float NearImpactTime;
    float LastAudioTime;
    float LocationVariance;
    FRuntimeFloatCurve DropImpactCurve;
    TSubclassOf<ARockCrackerPod> RockCrackerPod;
    TSubclassOf<AActor> RockCrackerIndicator;
    UDebrisPositioning* RockCrackerPodPositioning;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    TArray<ARockCrackerPod*> SpawnedPods;
    APlagueMeteor(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SignalEventStarted();
    void SignalEventEnded(bool wasSuccess);
    UFUNCTION(BlueprintCallable)
    void SetStage(int32 Stage);
    void SetDropTarget(const FVector& Location);
    void ResetStage();
    void RegressStage();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStageAdvanced(int32 Stage);
    UFUNCTION()
    void OnRep_DropInfo();
    UFUNCTION()
    void OnRep_CrackStage();
    void NearImpact();
    void LastaudioSignal();
    void Impacted_Latejoin();
    void Impacted();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasLandedOnTopOfRefineryPipes(float minDistanceToPipes) const;
    TArray<ARockCrackerPod*> GetPods();
    ARockCrackerPod* GetPodAtIndex(int32 Index);
    int32 GetNumActivePods() const;
    void EnableVisuals();
    void DropStarted();
    void DropRockCrackerPods(int32 amount, float MinRadius, float maRadius, AProceduralSetup* setup);
    void DestroyAndSpawnHearts_FailSafe();
    void AdvanceStage();
};
