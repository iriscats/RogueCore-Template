#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BehaviorTree/BehaviorTreeTypes.h"

#include "UObject/UnrealType.h"
#include "BTDecorator_CanSeeTarget.generated.h"

UCLASS(Blueprintable)
class UBTDecorator_CanSeeTarget : public UBTDecorator {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseAsync;
    
    bool DebugDraw;
    float MaxRange;
    float Interval;
    FVector EyeLocationOffset;
    FName EyeSocketName;
    FBlackboardKeySelector TargetKey;
    TEnumAsByte<ECollisionChannel> TraceChannel;
    bool UseTargetable;
    UBTDecorator_CanSeeTarget();
};
