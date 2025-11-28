#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DroneAbillityStatsComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UDroneAbillityStatsComponent : public UActorComponent {
    GENERATED_BODY()
    
public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseOwnArmorDamageMultiplier;
    
    UDroneAbillityStatsComponent(const FObjectInitializer& ObjectInitializer);
};
