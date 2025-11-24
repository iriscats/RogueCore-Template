#include "BoxProjectile.h"
#include "Components/BoxComponent.h"

ABoxProjectile::ABoxProjectile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer.SetDefaultSubobjectClass<UBoxComponent>(TEXT("SphereComponent"))) {
    this->CollisionComponent = (UShapeComponent*)RootComponent;
}


