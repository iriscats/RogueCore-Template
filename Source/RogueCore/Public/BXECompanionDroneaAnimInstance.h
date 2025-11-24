#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Animation/AnimInstance.h"
#include "EBXECompanionDroneState.h"
#include "BXECompanionDroneaAnimInstance.generated.h"

class ABXECompanionDrone;
class UAnimSequenceBase;
class UDeepPathfinderMovement;
UCLASS(Blueprintable, NonTransient)
class UBXECompanionDroneaAnimInstance : public UAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector MovementBlend;
    
    FVector2D LookBlend;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAnimSequenceBase*> IdleFlairs;
    TWeakObjectPtr<ABXECompanionDrone> drone;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UDeepPathfinderMovement> Movement;
    float MinFlairCooldown;
    float MaxFlairCooldown;
    float HorizontalAngularSpeed;
    float VerticalAngularSpeed;
    float Velocity;
    float UpAgnle;
    float DepositPlayRate;
    EBXECompanionDroneState State;
    bool Landed;
    bool Dispensing;
    bool Depositable;
    bool HasArtifact;
    bool HasPotentExpenite;
    UBXECompanionDroneaAnimInstance();
};
