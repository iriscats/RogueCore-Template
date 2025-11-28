#pragma once
#include "CoreMinimal.h"
#include "BXEUnlockCollection.h"
#include "BXEUnlockPool.generated.h"

class UBXEUnlockBase;
UCLASS(Blueprintable)
class ROGUECORE_API UBXEUnlockPool : public UBXEUnlockCollection {
    GENERATED_BODY()
    

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<UBXEUnlockBase*> Unlocks;
    
    UBXEUnlockBase* SkipReward;
    UBXEUnlockPool();
    UFUNCTION(BlueprintCallable)
    TArray<UBXEUnlockBase*> GetUnlocks();
};
