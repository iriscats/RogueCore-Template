#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "DroneTargetSensingComponent.generated.h"

class AActor;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UDroneTargetSensingComponent : public UActorComponent {
    GENERATED_BODY()
    

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagQuery TargetQuery;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* PulseFrom;
    float SensingRange;
    float SensingIntervals;
    bool NeedsLineOfSight;
    UDroneTargetSensingComponent(const FObjectInitializer& ObjectInitializer);
};
