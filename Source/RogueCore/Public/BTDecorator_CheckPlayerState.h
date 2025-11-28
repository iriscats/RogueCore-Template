#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "ECharacterState.h"
#include "BTDecorator_CheckPlayerState.generated.h"

UCLASS(Blueprintable)
class ROGUECORE_API UBTDecorator_CheckPlayerState : public UBTDecorator {
    GENERATED_BODY()
    


public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector TargetToCheck;
    
    TArray<ECharacterState> BannedStates;
    UBTDecorator_CheckPlayerState();
};
