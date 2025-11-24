#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlaceParametersSimple.h"
#include "ShieldPlacement.h"
#include "ThrowParameters.h"
#include "ThrowParametersSimple.h"
#include "ThrowLibrary.generated.h"

class AActor;
class APlacementDeviceActor;
class AThrowableActor;
UCLASS(Blueprintable)
class UThrowLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UThrowLibrary();
    UFUNCTION(BlueprintCallable)
    static AThrowableActor* ThrowActorSimple(const FThrowParametersSimple& ThrowParameters);
    
    static AThrowableActor* ThrowActor(const FThrowParameters& ThrowParameters);
    static APlacementDeviceActor* PlaceDevice(const FPlaceParametersSimple& PlaceParameters);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FShieldPlacement ComputeSmoothShieldPlacement(const AActor* ShieldedActor, const float ShieldDistanceToActor, const AActor* Shield, const float DeltaSeconds, const float RotationInterpolationSpeed, const float LocationInterpolationSpeed);
    static FShieldPlacement ComputeShieldPlacement(const AActor* ShieldedActor, const float ShieldDistanceToActor);
};
