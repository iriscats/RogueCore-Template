#include "CSGBuilderBase.h"

void ACSGBuilderBase::StaticRegisterNativesACSGBuilderBase() {
}

ACSGBuilderBase::ACSGBuilderBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PreviewSeed = 0;
    this->PreviewComponent = NULL;
}



