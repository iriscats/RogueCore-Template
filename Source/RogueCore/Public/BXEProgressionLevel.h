#pragma once
#include "CoreMinimal.h"
#include "BXEProgressionLevel.generated.h"

class UBXEUnlockBase;
class UUnlockCollectionTag;
USTRUCT(BlueprintType)
struct FBXEProgressionLevel {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RequiredXP;
    
    UUnlockCollectionTag* CollectionTag;
    TArray<UBXEUnlockBase*> AutomaticallyUnlocked;
    ROGUECORE_API FBXEProgressionLevel();
};
