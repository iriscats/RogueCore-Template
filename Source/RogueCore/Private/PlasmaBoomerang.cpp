#include "PlasmaBoomerang.h"
#include "Components/BoxComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "DamageComponent.h"

APlasmaBoomerang::APlasmaBoomerang(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->Root = (USceneComponent*)RootComponent;
    this->Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
    this->DamageComponent = CreateDefaultSubobject<UDamageComponent>(TEXT("Damage"));
    this->mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mesh"));
    this->MeshPivot = CreateDefaultSubobject<USceneComponent>(TEXT("MeshPivot"));
    this->ArcCurve = NULL;
    this->StartSmoothTime = 1.00f;
    this->RotationSpeed = 1750.00f;
    this->ArcSpeed = 1.25f;
    this->HomingAcceleration = 1.25f;
    this->IsHoming = false;
    this->Collision->SetupAttachment(RootComponent);
    this->MeshPivot->SetupAttachment(Collision);
    this->mesh->SetupAttachment(MeshPivot);
}

void APlasmaBoomerang::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}


