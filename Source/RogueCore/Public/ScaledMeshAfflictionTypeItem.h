#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "RandRange.h"
#include "ScaledMeshAfflictionTypeItem.generated.h"

class UFXSystemAsset;
class USoundCue;
class UStaticMesh;
USTRUCT(BlueprintType)
struct FScaledMeshAfflictionTypeItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRuntimeFloatCurve> Scalers;

    TArray<TSoftObjectPtr<UStaticMesh>> Meshes;
    FRandRange ScaleDelay;
    TSoftObjectPtr<USoundCue> StartingSound;
    TSoftObjectPtr<USoundCue> EndSound;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, EditFixedSize, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UFXSystemAsset>> StartParticles;
    TArray<TSoftObjectPtr<UFXSystemAsset>> EndParticles;
    ROGUECORE_API FScaledMeshAfflictionTypeItem();
};
