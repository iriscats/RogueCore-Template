#include "TimerRewinderGhost.h"
#include "Components/SceneComponent.h"
#include "Components/SkeletalMeshComponent.h"

ATimerRewinderGhost::ATimerRewinderGhost(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->Root = (USceneComponent*)RootComponent;
    this->CharacterMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh"));
    this->HologramMaterial = NULL;
    this->HologramAnimation = NULL;
    this->CharacterMesh->SetupAttachment(RootComponent);
}


