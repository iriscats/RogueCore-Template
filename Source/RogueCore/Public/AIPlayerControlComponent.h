#pragma once
#include "CoreMinimal.h"

#include "Components/ActorComponent.h"
#include "AIPlayerControlComponent.generated.h"

class UAnimMontage;
class UControlEnemyUsable;
class UDialogDataAsset;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UAIPlayerControlComponent : public UActorComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator AngularAcceleration;
    
    FRotator AngularDampening;
    FRotator MaxAngularVelocity;
    FRotator MaxRotation;
    float SpeedTarget;
    float SpeedMin;
    float SpeedMax;
    float AccelerationBase;
    float AccelerationMultiplier;
    float DecelerationMultiplier;
    float AccelerationOnSlopeMultiplier;
    float DecelerationOnSlopeMultiplier;
    float InitialConnectionBlendTime;
 
    UAnimMontage* GetOnMontageAI;
    UAnimMontage* GetOnMontagePlayer;
    UAnimMontage* LetGoMontageAI;
    UAnimMontage* LetGoMontagePlayer;
    UDialogDataAsset* GetOnShout;
    UDialogDataAsset* LetGoShout;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UControlEnemyUsable* usable;
    UAIPlayerControlComponent(const FObjectInitializer& ObjectInitializer);
};
