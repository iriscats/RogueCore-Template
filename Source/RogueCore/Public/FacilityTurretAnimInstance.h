#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EnemyAnimInstance.h"
#include "FacilityTurretAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UFacilityTurretAnimInstance : public UEnemyAnimInstance {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRotator AimRotation;
    
    bool IsEngaged;
    UFacilityTurretAnimInstance(const FObjectInitializer& ObjectInitializer);
};
