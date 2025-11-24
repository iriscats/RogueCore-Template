#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UObject/NoExportTypes.h"
#include "Targetable.generated.h"

class UFXSystemAsset;
class UHealthComponentBase;
UINTERFACE(Blueprintable)
class ROGUECORE_API UTargetable : public UInterface {
	GENERATED_BODY()
};
class ROGUECORE_API ITargetable : public IInterface {
	GENERATED_BODY()
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintNativeEvent)
    void ShowDamageEffects(UFXSystemAsset* Particles, FVector Location, FRotator Orientation);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UHealthComponentBase* GetTargetHealthComponent() const;
    FVector GetTargetCenterMass() const;
    bool GetIsTargetable() const;
};
