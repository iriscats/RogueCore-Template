#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "GameplayTagContainer.h"
#include "BTService_FindAttackable.generated.h"

class UAttackerPositioningComponent;
UCLASS(Blueprintable)
class UBTService_FindAttackable : public UBTService {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector TargetKey;
    
    bool MustBeAlive;
    bool MustBeDowned;
    bool IgnoreIncapacitated;
    bool SwithToBetterTargets;
    bool RegisterForPositioning;
    bool IsFlying;
    bool CanShoot;
    float TargetingRange;
    FGameplayTagQuery TargetQuery;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAttackerPositioningComponent* CurrentRegisteredTarget;
    UBTService_FindAttackable();
};
