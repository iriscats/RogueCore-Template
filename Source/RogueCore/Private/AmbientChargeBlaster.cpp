#include "AmbientChargeBlaster.h"
#include "ChargedProjectileLauncherComponent.h"

AAmbientChargeBlaster::AAmbientChargeBlaster(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ChargeProgressForOtherFireAnim = 0.90f;
    this->OtherFireAnimFP = NULL;
    this->OtherFireAnimTP = NULL;
    this->ChargeRecoilCurve = NULL;
    this->MuzzleParticlesWeak = NULL;
    this->LauncherComponent = CreateDefaultSubobject<UChargedProjectileLauncherComponent>(TEXT("ProjectileLauncherComponent"));
}


