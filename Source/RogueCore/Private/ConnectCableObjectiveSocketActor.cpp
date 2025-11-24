#include "ConnectCableObjectiveSocketActor.h"
#include "Components/ChildActorComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Net/UnrealNetwork.h"

AConnectCableObjectiveSocketActor::AConnectCableObjectiveSocketActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    this->IsDisabled = false;
    this->Root = (USceneComponent*)RootComponent;
    this->SocketMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SocketMesh"));
    this->FuelLineEndPoint = CreateDefaultSubobject<UChildActorComponent>(TEXT("FuelLineEndPoint"));
    this->FuelLineEndPoint->SetupAttachment(SocketMesh);
    this->SocketMesh->SetupAttachment(RootComponent);
}


void AConnectCableObjectiveSocketActor::OnConnectedWithSegment(UTrackBuilderConnectPoint* InConnectPoint, ATrackBuilderSegment* InSegment) {
}


void AConnectCableObjectiveSocketActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AConnectCableObjectiveSocketActor, IsDisabled);
}


