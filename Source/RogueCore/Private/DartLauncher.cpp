#include "DartLauncher.h"
#include "ProjectileLauncherComponent.h"

ADartLauncher::ADartLauncher(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->projectileLauncher = CreateDefaultSubobject<UProjectileLauncherComponent>(TEXT("Launcher"));
    this->MuzzleEffect = NULL;
    this->FP_FireAnimation = NULL;
    this->TP_FireAnimation = NULL;
    this->DeactivationTime = 0.20f;
    this->FireRate = 1.00f;
}

void ADartLauncher::Server_ShowFire_Implementation() {
}

void ADartLauncher::All_ShowFire_Implementation() {
}


