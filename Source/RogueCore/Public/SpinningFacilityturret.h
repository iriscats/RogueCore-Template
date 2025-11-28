#pragma once
#include "CoreMinimal.h"

#include "FacilityTurret.h"
#include "RandRange.h"
#include "SpinningFacilityturret.generated.h"

UCLASS(Blueprintable)
class ASpinningFacilityturret : public AFacilityTurret {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    FRotator TargetRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRandRange AimAtTargetEveryTurn;
    float TurnCooldown;
    float TurnTimer;
    float Acceptance;
    float TurnSpeed;
    ASpinningFacilityturret(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
