#include "BXEUnlockCollectionLibrary.h"

UBXEUnlockCollectionLibrary::UBXEUnlockCollectionLibrary() {
}

TArray<FBXEUnlockInstance> UBXEUnlockCollectionLibrary::PickRandomUnlocksFromTag(UObject* WorldContextObject, UUnlockCollectionTag* InTag, int32 InCount, FRandomStream& InRandomStream, const ERarityWeightType RarityWeightOverride) {
    return TArray<FBXEUnlockInstance>();
}

TArray<UUnlockCollectionTag*> UBXEUnlockCollectionLibrary::GetAllUnlockCollectionTags() {
    return TArray<UUnlockCollectionTag*>();
}


