#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GearStatEntry.h"
#include "UpgradableGear.generated.h"

class AFSDPlayerState;
UINTERFACE(Blueprintable)
class ROGUECORE_API UUpgradableGear : public UInterface {
	GENERATED_BODY()
};
class ROGUECORE_API IUpgradableGear : public IInterface {
	GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetGearStatEntry(AFSDPlayerState* PlayerState, UPARAM(Ref) TArray<FGearStatEntry>& Stats) const;
    
};