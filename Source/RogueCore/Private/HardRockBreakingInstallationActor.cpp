#include "HardRockBreakingInstallationActor.h"
#include "Components/SceneComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Runtime/UMG/Public/Components/WidgetComponent.h"
#include "Net/UnrealNetwork.h"
#include "OutlineComponent.h"
#include "PathfinderCollisionComponent.h"
#include "SimpleObjectInfoComponent.h"
#include "SingleUsableComponent.h"
#include "SpawnActorWithDebrisPosComponent.h"
#include "TerrainPlacementComponent.h"

AHardRockBreakingInstallationActor::AHardRockBreakingInstallationActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {

}

void AHardRockBreakingInstallationActor::OnUseTerminalScan(APlayerCharacter* User, EInputKeys Key) {
}

void AHardRockBreakingInstallationActor::OnUseTerminalBoot(APlayerCharacter* User, EInputKeys Key) {
}

void AHardRockBreakingInstallationActor::OnRep_Progress() {
}

void AHardRockBreakingInstallationActor::OnRep_MissingMachineParts() {
}

void AHardRockBreakingInstallationActor::OnRep_bHasScannedForMissingParts() {
}

void AHardRockBreakingInstallationActor::OnInitialGenerationDone() {
}


void AHardRockBreakingInstallationActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AHardRockBreakingInstallationActor, Progress);
    DOREPLIFETIME(AHardRockBreakingInstallationActor, MissingMachineParts);
    DOREPLIFETIME(AHardRockBreakingInstallationActor, CoreCrusherPartScannerMeshes);
    DOREPLIFETIME(AHardRockBreakingInstallationActor, bHasScannedForMissingParts);
}


