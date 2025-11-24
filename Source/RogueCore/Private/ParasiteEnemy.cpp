#include "ParasiteEnemy.h"
#include "Components/SceneComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/StaticMeshComponent.h"
#include "OutlineComponent.h"

AParasiteEnemy::AParasiteEnemy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->Root = (USceneComponent*)RootComponent;
    this->mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("mesh"));
    this->Tentacles1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tentacles1"));
    this->Tentacles2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tentacles2"));
    this->Outline = CreateDefaultSubobject<UOutlineComponent>(TEXT("Outline"));
    this->deathParticles = NULL;
    this->deathSound = NULL;
    this->Tentacles1->SetupAttachment(mesh);
    this->Tentacles2->SetupAttachment(mesh);
    this->mesh->SetupAttachment(RootComponent);
}

void AParasiteEnemy::OnSelfDeath(UHealthComponentBase* aHealthComponent) {
}


