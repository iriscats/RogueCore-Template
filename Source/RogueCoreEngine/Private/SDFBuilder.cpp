#include "SDFBuilder.h"
#include "SDFUnionOpComponent.h"

void ASDFBuilder::StaticRegisterNativesASDFBuilder() {
}

ASDFBuilder::ASDFBuilder(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USDFUnionOpComponent>(TEXT("SDFRoot"));
    this->PreviewSize = EPreviewCellSize::PRV_CELL_SIZE_50;
    this->SDFRoot = (USDFUnionOpComponent*)RootComponent;
}


