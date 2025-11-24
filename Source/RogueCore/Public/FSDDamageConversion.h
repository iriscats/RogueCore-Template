#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "DamageParams.h"
#include "FSDDamageConversion.generated.h"

class AActor;
UCLASS(Blueprintable)
class UFSDDamageConversion : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFSDDamageConversion();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FDamageParams ConvertToDamageParam(const FHitResult& HitResult, AActor* DamageCauser);
    
};
