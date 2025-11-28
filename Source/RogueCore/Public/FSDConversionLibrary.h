#pragma once
#include "CoreMinimal.h"

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/NetSerialization.h"
#include "FSDConversionLibrary.generated.h"

class AActor;
class USceneComponent;
UCLASS(Blueprintable)
class UFSDConversionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFSDConversionLibrary();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector_NetQuantizeNormal VectorToNetQuantizeNormal(FVector Vec);
    
    static FVector_NetQuantize VectorToNetQuantize(FVector Vec);
    static FVector QuatToVector(FQuat Quat);
    static FRotator QuatToRotator(FQuat Quat);
    static FVector_NetQuantizeNormal QuadToNetQuantizeNormal(FQuat Quat);
    static FVector ComponentToWorldLocation(USceneComponent* Component);
    static FVector ActorToWorldLocation(AActor* Actor);
};
