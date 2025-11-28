#pragma once
#include "CoreMinimal.h"

#include "Kismet/BlueprintFunctionLibrary.h"
#include "NoiseFunctionLibrary.generated.h"

class AActor;
class UObject;
class USceneComponent;
UCLASS(Blueprintable)
class UNoiseFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UNoiseFunctionLibrary();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SphericalNoiseMovementComponent(UObject* WorldContextObject, USceneComponent* Component, FVector Center, float Radius, float Speed, float TimeOffset);
    
    static void SphericalNoiseMovementActor(UObject* WorldContextObject, AActor* Actor, FVector Center, float Radius, float Speed, float TimeOffset);
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static FVector NoiseSphere3D(UObject* WorldContextObject, float Time, float Radius);
    static FVector2D NoiseSphere2D(UObject* WorldContextObject, float Time, float Radius);
    static float Noise3D(UObject* WorldContextObject, float X, float Y, float Z);
    static float Noise2D(UObject* WorldContextObject, float X, float Y);
    static float Noise(UObject* WorldContextObject, float X);
};
