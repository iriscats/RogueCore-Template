#pragma once
#include "CoreMinimal.h"
#include "BXEUnlockInstance.generated.h"

class AActor;
class UBXEUnlockBase;
class UBXEUnlockRarity;
class UItemUpgrade;
USTRUCT(BlueprintType)
struct FBXEUnlockInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UBXEUnlockBase* Unlock;
    
    UBXEUnlockRarity* UsedRarity;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CanBePickedMultipleTimes;
    TArray<TSoftObjectPtr<UItemUpgrade>> Attributes;
    AActor* PreviousActor;
    ROGUECORE_API FBXEUnlockInstance();
};
