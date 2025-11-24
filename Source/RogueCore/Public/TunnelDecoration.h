#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TunnelDecoration.generated.h"

class UDecorationSplineComponent;
class URoomSphereCollisionComponent;
class USceneComponent;
class UTerrainPlacementComponent;
UCLASS(Blueprintable, NoExport)
class ATunnelDecoration : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    UTerrainPlacementComponent* terrainPlacement;
    URoomSphereCollisionComponent* RoomSphereCollision;
    UDecorationSplineComponent* TunnelReshapeSpline;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldForceSpawn;
    ATunnelDecoration(const FObjectInitializer& ObjectInitializer);
};
