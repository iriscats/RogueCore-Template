#include "FirstPersonNiagaraComponent.h"
#include "UObject/UnrealType.h"

UFirstPersonNiagaraComponent::UFirstPersonNiagaraComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->FirstPersonPrimitiveType = EFirstPersonPrimitiveType::FirstPerson;
}

UNiagaraComponent* UFirstPersonNiagaraComponent::SpawnFirstPersonEmitterAttached(UNiagaraSystem* inNiagaraSystem, USceneComponent* AttachToComponent, FName AttachPointName, FVector Location, FRotator Rotation, FVector Scale, TEnumAsByte<EAttachLocation::Type> LocationType, bool inAutoDestroy) {
    return NULL;
}


