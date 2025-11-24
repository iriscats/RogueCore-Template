#pragma once
#include "CoreMinimal.h"
#include "EElementEventLockType.h"
#include "ElementConditionArray.h"
#include "RandRange.h"
#include "Templates/SubclassOf.h"
#include "ElementEventSetup.generated.h"

class UElementEventComponent;
class UStatusEffect;
USTRUCT(BlueprintType)
struct FElementEventSetup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ActivationCost;

    float DeactivationCost;
    float DeactivationImmunityTime;
    FRandRange EventStateDurationRange;
    float EventStateVariance;
    EElementEventLockType ElementStateLockType;
    FRandRange LockDurationRange;
    float LockVariance;
    TArray<TSubclassOf<UStatusEffect>> StatusEffectsToApply;
    TSoftClassPtr<UElementEventComponent> EventComponentSoftPtr;
    FElementConditionArray StayActiveConditions;
    ROGUECORE_API FElementEventSetup();
};
