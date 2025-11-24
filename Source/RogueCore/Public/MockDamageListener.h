#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "MockDamageListener.generated.h"

UCLASS(Blueprintable)
class UMockDamageListener : public UObject {
    GENERATED_BODY()
public:
    UMockDamageListener();
    UFUNCTION(BlueprintCallable)
    void RadialDamageTaken(float Damage, float BaseDamage, const FVector& position, float Radius);
    
};
