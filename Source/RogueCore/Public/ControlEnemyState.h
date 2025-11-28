#pragma once
#include "CoreMinimal.h"

#include "ControlEnemyState.generated.h"

class ADeepPathfinderCharacter;
USTRUCT(BlueprintType)
struct FControlEnemyState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ADeepPathfinderCharacter* ControlledEnemy;
    
    FTransform InitialTargetTransform;
    float InitialTargetBlendTotalTime;
    FVector InitialCharacterVelocity;
    FVector InitialEnemyVelocity;
    ROGUECORE_API FControlEnemyState();
};
