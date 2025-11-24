#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BXEUnlockInstance.h"
#include "ERarityWeightType.h"
#include "BXEUnlockCollectionLibrary.generated.h"

class UObject;
class UUnlockCollectionTag;
UCLASS(Blueprintable)
class UBXEUnlockCollectionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UBXEUnlockCollectionLibrary();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static TArray<FBXEUnlockInstance> PickRandomUnlocksFromTag(UObject* WorldContextObject, UUnlockCollectionTag* InTag, int32 InCount, UPARAM(Ref) FRandomStream& InRandomStream, const ERarityWeightType RarityWeightOverride);
    
    UFUNCTION(BlueprintCallable)
    static TArray<UUnlockCollectionTag*> GetAllUnlockCollectionTags();
};
