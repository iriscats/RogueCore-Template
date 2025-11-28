#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "DroneStateComponentBase.h"
#include "DroneCombatState.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UDroneCombatState : public UDroneStateComponentBase {
    GENERATED_BODY()
    
public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagQuery AttackOnOrderQuery;
    
    FGameplayTagQuery AttackOnSightQuery;
    UDroneCombatState(const FObjectInitializer& ObjectInitializer);
};
