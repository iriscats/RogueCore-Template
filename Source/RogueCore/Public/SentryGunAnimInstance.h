#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Animation/AnimInstance.h"
#include "SentryGunAnimInstance.generated.h"

class ARedeployableSentryGun;
class ASentryGun;
UCLASS(Abstract, Blueprintable, NonTransient)
class USentryGunAnimInstance : public UAnimInstance {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ASentryGun* SentryGun;
    
    ARedeployableSentryGun* RedeployableSentryGun;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator TurretRotation;
    float YawOffset;
    float BuildProgress;
    USentryGunAnimInstance();
};
