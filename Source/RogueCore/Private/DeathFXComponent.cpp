#include "DeathFXComponent.h"
#include "Net/UnrealNetwork.h"

UDeathFXComponent::UDeathFXComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CrossbowChemicalExplosionStatusEffect = NULL;
    this->PlasmaExplosionStatusEffect = NULL;
    this->PlasmaExplosionDOTStatusEffect = NULL;
    this->GibParticles = NULL;
    this->GoreMesh = NULL;
    this->HeadGoreMeshAttachSocket = TEXT("Neck_Guts");
    this->HeadshotParticles = NULL;
    this->HeadshotFXSocket = TEXT("Armor_Head");
    this->deathParticles = NULL;
    this->DeathMaterialOverride = NULL;
    this->BloodSquirtParticles = NULL;
    this->BurnDeathParticles = NULL;
    this->FrozenDeathParticles = NULL;
    this->CorrosiveDeathParticles = NULL;
    this->CookedDeathParticles = NULL;
    this->ChemicalExplosionDeathParticles = NULL;
    this->DeathSplatDecal = NULL;
    this->DeathSplatDecalSize = 0.00f;
    this->NotLocalInstigator_SoundClassOverride = NULL;
    this->NotLocalInstigator_SoundAttenuationOverride = NULL;
    this->deathSound = NULL;
    this->HeadshotGibsSound = NULL;
    this->BurnDeathSound = NULL;
    this->CorrosiveDeathSound = NULL;
    this->CookedDeathSound = NULL;
    this->ChemicalExplosionPreDeathSound = NULL;
    this->ChemicalExplosionDeathSound = NULL;
    this->DeathSplatSound = NULL;
    this->DissolveDelay = 0.00f;
    this->DissolveBaseShader = NULL;
    this->BurnBaseShader = NULL;
    this->CorrosiveBaseShader = NULL;
    this->RagdollEnabled = true;
    this->RagdollPhysicsAsset = NULL;
    this->CameraShake = NULL;
    this->DeathDuration = 20.00f;
    this->PostBurnRagdollDelay = 1.50f;
    this->LimbDismembermentList = NULL;
    this->HeadGoreMesh = NULL;
    this->SkeletalMesh = NULL;
    this->FSDPawn = NULL;
    this->PFCharacter = NULL;
    this->AnimInstance = NULL;
}

void UDeathFXComponent::OnRep_DeathType() {
}

void UDeathFXComponent::OnDeathDetailed(UHealthComponent* HealthComponent, float damageAmount, const FDamageData& DamageData, const TArray<UDamageTag*>& Tags) {
}

UStaticMeshComponent* UDeathFXComponent::CreateHeadGore() {
    return NULL;
}

void UDeathFXComponent::AllRagdoll_Implementation(const FVector_NetQuantize& Impulse, const FVector_NetQuantize& Location, int32 BoneIndex) {
}

void UDeathFXComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UDeathFXComponent, DeathType);
}


