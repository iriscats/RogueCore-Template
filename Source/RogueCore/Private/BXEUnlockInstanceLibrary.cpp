#include "BXEUnlockInstanceLibrary.h"

UBXEUnlockInstanceLibrary::UBXEUnlockInstanceLibrary() {
}

void UBXEUnlockInstanceLibrary::PlayUnlockInstanceSelectedSound2D(const UObject* WorldContext, const FBXEUnlockInstance& UnlockInstance) {
}

UUnlockVisualSettings* UBXEUnlockInstanceLibrary::GetUnlockInstanceVisualSettings(const FBXEUnlockInstance& UnlockInstance) {
    return NULL;
}

EUnlockType UBXEUnlockInstanceLibrary::GetUnlockInstanceType(const FBXEUnlockInstance& UnlockInstance) {
    return EUnlockType::Upgrade;
}

UBXEUnlockRarity* UBXEUnlockInstanceLibrary::GetUnlockInstanceRarity(const FBXEUnlockInstance& UnlockInstance) {
    return NULL;
}


