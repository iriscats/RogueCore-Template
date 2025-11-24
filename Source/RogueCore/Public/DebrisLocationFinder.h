#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DelegateDelegate.h"
#include "DebrisLocationFinder.generated.h"

class UDebrisPositioning;
class UTerrainPlacementComponent;
UCLASS(Abstract, Blueprintable, NoExport)
class ROGUECORE_API ADebrisLocationFinder : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnFailedDelegate;

    FDelegate OnSuceesDelegate;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDebrisPositioning* Positioning;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTerrainPlacementComponent* terrainPlacement;
protected:
    float MinRadius;
    float MaxRadius;
    float MaxExtraRadius;
    float MinDistanceToImportantRadius;
    int32 MaxIteration;
    int32 MaxChunksPerFrame;
    bool DestroyOnFinish;
    bool StopAtEnoughMatches;
    ADebrisLocationFinder(const FObjectInitializer& ObjectInitializer);
};
