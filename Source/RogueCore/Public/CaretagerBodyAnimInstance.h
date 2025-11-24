#pragma once
#include "CoreMinimal.h"
#include "EnemyAnimInstance.h"
#include "CaretagerBodyAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UCaretagerBodyAnimInstance : public UEnemyAnimInstance {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool CoolingOff;

    bool IsWeakpointAVisible;

    bool IsWeakpointBVisible;

    bool IsWeakpointCVisible;

    bool IsWeakpointDVisible;

    float RotationAngle;

    int32 AoEStage;

    bool IsSpawningDrones;

    bool IsSpawningBombs;

    bool IsSpawningShredders;

    bool IsSpawningTurrets;

public:
    UCaretagerBodyAnimInstance();
};
