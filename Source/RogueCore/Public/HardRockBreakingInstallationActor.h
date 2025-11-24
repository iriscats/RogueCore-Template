#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DelegateEventDelegate.h"
#include "EInputKeys.h"
#include "HardRockBreakerProgressSignatureDelegate.h"
#include "Templates/SubclassOf.h"
#include "HardRockBreakingInstallationActor.generated.h"

class AGameEvent;
class APlayerCharacter;
class UCurveFloat;
class UDebrisPositioning;
class UOutlineComponent;
class UPathfinderCollisionComponent;
class UPrimitiveComponent;
class USceneComponent;
class USimpleObjectInfoComponent;
class USingleUsableComponent;
class USkeletalMeshComponent;
class USpawnActorWithDebrisPosComponent;
class USphereComponent;
class UTerrainPlacementComponent;
class UWidgetComponent;
UCLASS(Blueprintable, NoExport)
class ROGUECORE_API AHardRockBreakingInstallationActor : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_bHasScannedForMissingParts, meta=(AllowPrivateAccess=true))

    bool bHasScannedForMissingParts;

    AHardRockBreakingInstallationActor(const FObjectInitializer& ObjectInitializer);



public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    UTerrainPlacementComponent* terrainPlacement;
    USkeletalMeshComponent* TerminalMesh;
    UWidgetComponent* TerminalDisplayWidget;
    USphereComponent* TerminalUsableCollider;
    USceneComponent* ExpeniteSpawnPoint;
    UPathfinderCollisionComponent* PathfinderCollision;
    USpawnActorWithDebrisPosComponent* SpawnActorWithDebrisPosition;
    UOutlineComponent* Outline;
    USimpleObjectInfoComponent* SimpleObjectInfo;
    USingleUsableComponent* ScanTerminalUsable;
    USingleUsableComponent* BootTerminalUsable;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> CoreCrusherPart;
    UDebrisPositioning* CoreCrusherPartPositioning;
    UCurveFloat* CoreCrusherPartCostCurve;
    TSubclassOf<AGameEvent> DefenceEvent;
    float ExpeniteChunkSize;
    int32 ExpeniteChunkAmount;
    float PartsSpawnRange;
    float TimePerCoreCrusher;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Progress, meta=(AllowPrivateAccess=true))
    float Progress;
    int32 WorkingCoreCrushers;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_MissingMachineParts, meta=(AllowPrivateAccess=true))
    int32 MissingMachineParts;
    bool bHasRunInitialActivation;
protected:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHardRockBreakerProgressSignature OnProgress;
    FDelegateEvent OnReadyToStart;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Replicated, meta=(AllowPrivateAccess=true))
    TArray<UPrimitiveComponent*> CoreCrusherPartScannerMeshes;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_bHasScannedForMissingParts, meta=(AllowPrivateAccess=true))
    bool bHasScannedForMissingParts;
    AHardRockBreakingInstallationActor(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnUseTerminalScan(APlayerCharacter* User, EInputKeys Key);
    void OnUseTerminalBoot(APlayerCharacter* User, EInputKeys Key);
    UFUNCTION()
    void OnRep_Progress();
    UFUNCTION()
    void OnRep_MissingMachineParts();
    UFUNCTION()
    void OnRep_bHasScannedForMissingParts();
    void OnInitialGenerationDone();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEventStarted();
};
