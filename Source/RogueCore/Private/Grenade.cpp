#include "Grenade.h"
#include "UObject/UnrealType.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

AGrenade::AGrenade(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    const FProperty* p_PhysicsReplicationMode = GetClass()->FindPropertyByName("PhysicsReplicationMode");
    (*p_PhysicsReplicationMode->ContainerPtrToValuePtr<EPhysicsReplicationMode>(this)) = EPhysicsReplicationMode::PredictiveInterpolation;
    this->CrossHairType = NULL;
    this->Movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
    this->UpgradeContainer = NULL;
    this->ProjectionSettings = NULL;
    this->CookingSound = NULL;
    this->HandAttachMesh = NULL;
    this->ItemID = NULL;
    this->ImpactGroundSound = NULL;
    this->ImpactGroundParticles = NULL;
    this->GrenadeAnimationSetOverride = NULL;
    this->WeaponPreviewClass = NULL;
    this->LoadoutProxy = NULL;
    this->CoolDown = -1.00f;
    this->Duration = 0.00f;
    this->cookTime = -1.00f;
    this->ExplosionDelay = 0.00f;
    this->IsReturningToSender = false;
    this->MaxGrenades = 0;
    this->CanCook = false;
    this->ExplodeOnImpact = false;
    this->HasExploded = false;
    this->CountDownBegun = false;
    this->RemainingDuration = 0.00f;
}

void AGrenade::OnRep_HasExploded() {
}


bool AGrenade::IsNonFriendlyPawn(AActor* Actor) const {
    return false;
}

bool AGrenade::IsNonFriendly(AActor* Actor) const {
    return false;
}

TSubclassOf<AActor> AGrenade::GetWeaponViewClass() const {
    return NULL;
}

AGrenade* AGrenade::GetGrenadeDefaultObject(TSubclassOf<AGrenade> GrenadeClass) {
    return NULL;
}

void AGrenade::CopyUpgradeFromGrenade(AActor* To) {
}

void AGrenade::ActorWasHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit) {
}

void AGrenade::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AGrenade, Duration);
    DOREPLIFETIME(AGrenade, HasExploded);
}


