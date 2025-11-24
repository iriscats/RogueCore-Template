#include "BioBoosterTerminal.h"
#include "Components/SceneComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Runtime/UMG/Public/Components/WidgetComponent.h"
#include "BioBoosterTerminalUsable.h"
#include "HackingUsableComponent.h"

ABioBoosterTerminal::ABioBoosterTerminal(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
    this->RewardCount = 2;
    this->SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
    this->HackTerminalUsable = CreateDefaultSubobject<UHackingUsableComponent>(TEXT("HackTerminalUsable"));
    this->PlayerInterfaceUsable = CreateDefaultSubobject<UBioBoosterTerminalUsable>(TEXT("PlayerInterfaceUsable"));
    this->PlayerInterfaceWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("PlayerInterfaceComponent"));
    this->SelectorWidget = NULL;
    this->BioBoosterDeck = NULL;
    this->PlayerInterfaceWidget->SetupAttachment(SkeletalMeshComponent);
    this->SkeletalMeshComponent->SetupAttachment(RootComponent);
}


void ABioBoosterTerminal::OnPlayerInterfaceVisibilityChanged(ESlateVisibility InVisibility) {
}

void ABioBoosterTerminal::OnPlayerInterfaceUsed(APlayerCharacter* InPlayer) {
}

void ABioBoosterTerminal::OnPlayerInterfaceUnhovered(APlayerCharacter* InPlayer) {
}

void ABioBoosterTerminal::OnPlayerInterfaceProgress(float InProgress) {
}

void ABioBoosterTerminal::OnPlayerInterfaceHovered(APlayerCharacter* InPlayer) {
}

void ABioBoosterTerminal::OnActivateTerminalUsed(APlayerCharacter* InPlayer) {
}

bool ABioBoosterTerminal::GetIsInterfaceVisible() const {
    return false;
}


