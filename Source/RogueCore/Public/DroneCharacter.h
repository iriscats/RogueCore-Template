#pragma once
#include "CoreMinimal.h"
#include "DeepPathfinderCharacter.h"
#include "DroneCharacter.generated.h"

class UHealthComponent;
class UOutlineComponent;
class USimpleObjectInfoComponent;
UCLASS(Abstract, Blueprintable)
class ADroneCharacter : public ADeepPathfinderCharacter {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHealthComponent* HealthComponent;
    
    UOutlineComponent* OutlineComponent;
    USimpleObjectInfoComponent* ObjectInfo;
    ADroneCharacter(const FObjectInitializer& ObjectInitializer);
};
