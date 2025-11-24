#include "TentaclePlantNode.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Net/UnrealNetwork.h"

ATentaclePlantNode::ATentaclePlantNode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mesh"));
    this->TentacleCableType = NULL;
    this->TentacleCable = NULL;
    this->TentaclePlant = NULL;
    this->TentacleIndex = -1;
    this->mesh->SetupAttachment(RootComponent);
}

void ATentaclePlantNode::OnPathCompleted(bool wasCompleted) {
}

void ATentaclePlantNode::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ATentaclePlantNode, TentaclePlant);
    DOREPLIFETIME(ATentaclePlantNode, TentacleIndex);
}


