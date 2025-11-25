#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BXEProspectingRewardActor.generated.h"

class UBXEProspectingLogsObjective;
class USceneComponent;
class UTerrainPlacementComponent;
class UTerrainScannerStaticMesh;
UCLASS(Blueprintable)
class ABXEProspectingRewardActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTerrainScannerStaticMesh* ScannerArea;
    
    UTerrainPlacementComponent* terrainPlacement;
    USceneComponent* Root;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UBXEProspectingLogsObjective* Objective;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float maxOffset;
    ABXEProspectingRewardActor(const FObjectInitializer& ObjectInitializer);
};
