#pragma once
#include "CoreMinimal.h"
#include "CharacterSightSensorBase.h"
#include "CharacterSightSensor.generated.h"

class UCharacterSightSensor;
class UPrimitiveComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCharacterSightSensor : public UCharacterSightSensorBase {
    GENERATED_BODY()

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCharacterSightSensorDelegate, UCharacterSightSensor*, Sensor);

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCharacterSightSensorDelegate OnSensorActivated;

    FCharacterSightSensorDelegate OnSensorDeactivated;

protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SensorActiveForMinDuration;

    float MinimumDistance;

    float MaximumDistance;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UPrimitiveComponent*> RestrictToColliders;

    bool bSensorActivated;

    float TimeActive;

    float LastSeenTime;

public:
    UCharacterSightSensor(const FObjectInitializer& ObjectInitializer);
};
