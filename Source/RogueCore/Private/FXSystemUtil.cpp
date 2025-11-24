#include "FXSystemUtil.h"

UFXSystemUtil::UFXSystemUtil() {
}

UFXSystemComponent* UFXSystemUtil::SpawnFXSystemAtLocation(const UObject* WorldContextObject, UFXSystemAsset* FXSystem, FVector Location, FRotator Rotation, FVector Scale, bool bAutoDestroy, bool bAutoActivate, ENCPoolMethod PoolingMethod, bool bPreCullCheck) {
    return NULL;
}

UFXSystemComponent* UFXSystemUtil::SpawnFirstPersonEmitterAttached(UFXSystemAsset* FXSystem, USceneComponent* AttachToComponent, FName AttachPointName, FVector Location, FRotator Rotation, FVector Scale, TEnumAsByte<EAttachLocation::Type> LocationType, bool inAutoDestroy) {
    return NULL;
}

bool UFXSystemUtil::IsFXSystemAsset(const UFXSystemComponent* FXComp, const UFXSystemAsset* FXAsset) {
    return false;
}


