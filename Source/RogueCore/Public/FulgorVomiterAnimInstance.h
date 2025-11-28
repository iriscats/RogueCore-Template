#pragma once
#include "CoreMinimal.h"

#include "EnemyAnimInstance.h"
#include "FulgorVomiterAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class ROGUECORE_API UFulgorVomiterAnimInstance : public UEnemyAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsExtended;
    
    bool IsAiming;
    FVector2D AimDirection;
    UFulgorVomiterAnimInstance(const FObjectInitializer& ObjectInitializer);
};
