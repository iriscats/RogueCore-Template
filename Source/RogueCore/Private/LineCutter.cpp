#include "LineCutter.h"
#include "Net/UnrealNetwork.h"
#include "ProjectileLauncherComponent.h"

ALineCutter::ALineCutter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->StopUsingReversesProjectile = false;
    this->RotateProjectileUntillStop = false;
    this->ExplodeLastProjectileOnNextFireAttempt = false;
    this->MinExplosiveGoodbyeActivationTimme = 0.50f;
    this->LauncherComponent = CreateDefaultSubobject<UProjectileLauncherComponent>(TEXT("ProjectileLauncherComponent"));
}

void ALineCutter::Server_StopRotatingProjectile_Implementation() {
}

bool ALineCutter::Server_StopRotatingProjectile_Validate() {
    return true;
}

void ALineCutter::Server_ReverseLastProjectile_Implementation() {
}

bool ALineCutter::Server_ReverseLastProjectile_Validate() {
    return true;
}

void ALineCutter::Server_DestroyOldProjectile_Implementation() {
}

bool ALineCutter::Server_DestroyOldProjectile_Validate() {
    return true;
}

void ALineCutter::OnRep_LastProjectile() const {
}

void ALineCutter::OnProjectileLaunched(AProjectileBase* Projectile) {
}


void ALineCutter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ALineCutter, LastProjectile);
}


