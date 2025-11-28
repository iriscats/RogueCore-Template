#pragma once
#include "CoreMinimal.h"

#include "Components/SceneComponent.h"
#include "DebrisCapsule.h"
#include "EDebrisColliderType.h"
#include "TerrainPlacementBox.h"
#include "TerrainPlacementComponent.generated.h"

class AProceduralSetup;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UTerrainPlacementComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTerrainPlacementBox> TerrainCheckers;
    
    EDebrisColliderType CapsuleType;
    FDebrisCapsule Capsule;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 BlockerIDHack;
 
    bool bAddBlockerOnSpawn;
    UTerrainPlacementComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void RemoveBlockers();
    void AddBlockers(AProceduralSetup* ProceduralSetup, const FTransform& Transform);
};
