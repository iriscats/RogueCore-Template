#pragma once
#include "CoreMinimal.h"
#include "DroneStateComponentBase.h"
#include "DroneFollowState.generated.h"

class AActor;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UDroneFollowState : public UDroneStateComponentBase {
    GENERATED_BODY()
    

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* FollowTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxFollowRadius;
    float MinFollowRadius;
    float UpdateLocationInterval;
    float UpdateLocationVariance;
    UDroneFollowState(const FObjectInitializer& ObjectInitializer);
};
