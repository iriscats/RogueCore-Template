#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DLCBase.generated.h"

class UDLCBase;
UCLASS(Blueprintable)
class ROGUECORE_API UDLCBase : public UDataAsset {
    GENERATED_BODY()
public:
    UDLCBase();
    UFUNCTION(BlueprintCallable)
    static void QueryAllDLC();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsUnlocked() const;
    static bool IsDLCUnLocked(UDLCBase* dlc);
};
