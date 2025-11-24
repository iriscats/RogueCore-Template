#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EDroneState.h"
#include "DroneStateComponentBase.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UDroneStateComponentBase : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDroneState SubsequentState;
    
    UDroneStateComponentBase(const FObjectInitializer& ObjectInitializer);
};
