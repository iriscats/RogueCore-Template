#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BTDecorator_IsUnderCeiling.generated.h"

UCLASS(Blueprintable)
class UBTDecorator_IsUnderCeiling : public UBTDecorator {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ProjectileAttackName;
    
    FName SocketName;
    float Acceptance;
    bool DrawDebug;
    FBlackboardKeySelector TargetKey;
    UBTDecorator_IsUnderCeiling();
};
