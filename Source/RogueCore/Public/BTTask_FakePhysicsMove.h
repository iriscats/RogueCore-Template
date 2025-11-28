#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"

#include "BTTask_FakePhysicsMove.generated.h"

class UFakeMoverSettings;
UCLASS(Blueprintable)
class UBTTask_FakePhysicsMove : public UBTTask_BlackboardBase {
    GENERATED_BODY()
    

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinTime;
    
    float EndMaxSpeed;
    FVector InitialLocalVelocity;
    FVector InitialGlobalVelocity;
    bool EndRequireSolidGround;
    UFakeMoverSettings* MoveSettings;
    UBTTask_FakePhysicsMove();
};
