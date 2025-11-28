#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ConvertedRobotTurretAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UConvertedRobotTurretAnimInstance : public UAnimInstance {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool ReplaceBurstAttack;
    
    bool IsFiringGrenades;
    bool IsDoingSpecialAttack;
    bool ShouldFireBullets;
    bool StopFiringBullets;
    bool ShouldCannonDeploy;
    UConvertedRobotTurretAnimInstance();
};
