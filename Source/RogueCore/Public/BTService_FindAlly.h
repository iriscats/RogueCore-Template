#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "EAllyQuerySorting.h"
#include "BTService_FindAlly.generated.h"

class UAllyQueryAsset;
class UFindAllyConditionBase;
UCLASS(Blueprintable)
class ROGUECORE_API UBTService_FindAlly : public UBTService {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UFindAllyConditionBase*> Conditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxSameTypeSupportingActors;
    UAllyQueryAsset* Query;
    FBlackboardKeySelector TargetKey;
    TEnumAsByte<EAllyQuerySorting> Sorting;
    float MaxRange;
    bool MustBeAlive;
    bool UpdateTarget;
    UBTService_FindAlly();
};
