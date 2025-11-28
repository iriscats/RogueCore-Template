#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AmmoDrivenWeaponAnimInstance.h"
#include "BeltDrivenAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UBeltDrivenAnimInstance : public UAmmoDrivenWeaponAnimInstance {
    GENERATED_BODY()
    

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))

    float CurrentBarrelSpinRate;

    FVector ExternalForce;

    float ExternalForceScale;

    FName ExternalForceBoneName;

    UBeltDrivenAnimInstance();

};
