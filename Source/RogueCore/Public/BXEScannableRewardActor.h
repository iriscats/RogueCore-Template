#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BXEScannableRewardActor.generated.h"

class UBXEObjectiveLostDronesTreasure;
class USceneComponent;
class UTerrainPlacementComponent;
class UTerrainScannerStaticMesh;
UCLASS(Blueprintable)
class ABXEScannableRewardActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTerrainScannerStaticMesh* ScannerArea;
    
    UTerrainPlacementComponent* terrainPlacement;
    USceneComponent* Root;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UBXEObjectiveLostDronesTreasure* Objective;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float maxOffset;
    ABXEScannableRewardActor(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void RewardObtained();
};
