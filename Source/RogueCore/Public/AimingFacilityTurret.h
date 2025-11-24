#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EIndicatorMode.h"
#include "FacilityTurret.h"
#include "AimingFacilityTurret.generated.h"

class UFXSystemComponent;
UCLASS(Blueprintable, NoExport)
class AAimingFacilityTurret : public AFacilityTurret {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IndicatorMode, meta=(AllowPrivateAccess=true))
    EIndicatorMode IndicatorMode;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInt32Interval BurstCount;
    void SetupAimindicator(UFXSystemComponent* NewAimIndicator, UFXSystemComponent* NewAimIndicatorLock);
    void OnRep_IsLockedOn();
    void OnRep_IndicatorMode();
    void OnLockedOn(bool lockedOn);
};