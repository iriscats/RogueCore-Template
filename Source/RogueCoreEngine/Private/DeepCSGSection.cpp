#include "DeepCSGSection.h"
#include "DeepProceduralMeshComponent.h"

void ADeepCSGSection::StaticRegisterNativesADeepCSGSection() {
}

ADeepCSGSection::ADeepCSGSection(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<UDeepProceduralMeshComponent>(TEXT("DeepMesh"));
    this->DeepMesh = (UDeepProceduralMeshComponent*)RootComponent;
}


