#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "UObject/NoExportTypes.h"
#include "BTDecorator_CheckObstruction.generated.h"

UCLASS(Blueprintable)
class UBTDecorator_CheckObstruction : public UBTDecorator {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Range;
    
    bool UseOwnerCenterMass;
    FVector EyeLocationOffset;
    FName RangedSocket;
    FBlackboardKeySelector TargetKey;
    UBTDecorator_CheckObstruction();
};
