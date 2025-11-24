#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CoreTentacleMovementTarget.generated.h"

class AActor;
USTRUCT(BlueprintType)
struct FCoreTentacleMovementTarget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MovementTimeInSeconds;
    
    float SwayCooldownInSeconds;
    FVector MoveTo;
    FVector LookAt;
    TWeakObjectPtr<AActor> MoveToActor;
    TWeakObjectPtr<AActor> LookAtActor;
    ROGUECORE_API FCoreTentacleMovementTarget();
};
