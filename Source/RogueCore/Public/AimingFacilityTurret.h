#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EIndicatorMode.h"
#include "FacilityTurret.h"
#include "AimingFacilityTurret.generated.h"

class UFXSystemComponent;
UCLASS(Blueprintable)
class AAimingFacilityTurret : public AFacilityTurret {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IndicatorMode, meta=(AllowPrivateAccess=true))
    EIndicatorMode IndicatorMode;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UFXSystemComponent* aimIndicator;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UFXSystemComponent* aimIndicatorLock;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsLockedOn, meta=(AllowPrivateAccess=true))
    bool IsLockedOn;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LockOnTime;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BurstInterval;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FireInterval;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TurretRotationSpeed;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InitialLockonDelay;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RegainLosLockonModifier;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AimZOffset;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TargetLeadingStrength;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TargetLeadingResponsiveness;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RaimainAfterShotTime;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TargetLeadingAfterLockonMultiplier;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TurningSpeedAfterLockOnMultipier;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PreLockonTargetChangeChance;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PreLockongTargetChangeRate;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IndicatorFlashTime;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool TrackTargetAfterLockon;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ConstantAimAfterLock;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseTraceForLockOn;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInt32Interval BurstCount;
    AAimingFacilityTurret(const FObjectInitializer& ObjectInitializer);
    void SetupAimindicator(UFXSystemComponent* NewAimIndicator, UFXSystemComponent* NewAimIndicatorLock);
    UFUNCTION()
    void OnRep_IsLockedOn();
    UFUNCTION()
    void OnRep_IndicatorMode();
    void OnLockedOn(bool lockedOn);
};