#include "DamageComponentBase.h"

UDamageComponentBase::UDamageComponentBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DamageComponentType = EDamageComponentType::Primary;
}

void UDamageComponentBase::DamageTarget(AActor* Target, const FVector& Location, UPrimitiveComponent* HitComponent, UFSDPhysicalMaterial* Material, int32 BoneIndex, EOverrideCrit overrideCrit, int32 overrideCritLevel) const {
}

void UDamageComponentBase::DamageArmor_Server(AActor* Target, UPrimitiveComponent* collider, int32 BoneIndex, const FVector& impactLocation) const {
}

void UDamageComponentBase::DamageArmor_All(AActor* Target, UPrimitiveComponent* collider, int32 BoneIndex) const {
}

bool UDamageComponentBase::ArmorSupportsLocalOnlyCall(AActor* Target) const {
    return false;
}


