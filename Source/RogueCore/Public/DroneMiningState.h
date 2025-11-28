#pragma once
#include "CoreMinimal.h"
#include "DroneStateComponentBase.h"
#include "DroneMiningState.generated.h"

class UDroneMiningToolBase;
class UTerrainMaterial;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UDroneMiningState : public UDroneStateComponentBase {
    GENERATED_BODY()
    

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UDroneMiningToolBase* DroneMiningTool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTerrainMaterial* HeartStoneMateiral;
    float StartMiningRange;
    float MiningRange;
    float SameHitRadius;
    float MineRadius;
    int32 MiningStrength;
    float EmbeddedSearchRadius;
    UDroneMiningState(const FObjectInitializer& ObjectInitializer);
};
