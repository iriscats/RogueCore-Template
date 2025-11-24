#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BTService_FindClosest.generated.h"

class UTargetValidator;
UCLASS(Blueprintable)
class ROGUECORE_API UBTService_FindClosest : public UBTService {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector TargetKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTargetValidator* TargetValidator;
    bool MustBeAlive;
    bool OwnerIsMultiTargeter;
    bool ClearTargetIfNotValid;
    float TargetingRange;
    UBTService_FindClosest();
};
