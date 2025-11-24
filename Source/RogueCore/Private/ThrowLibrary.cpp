#include "ThrowLibrary.h"

UThrowLibrary::UThrowLibrary() {
}

AThrowableActor* UThrowLibrary::ThrowActorSimple(const FThrowParametersSimple& ThrowParameters) {
    return NULL;
}

AThrowableActor* UThrowLibrary::ThrowActor(const FThrowParameters& ThrowParameters) {
    return NULL;
}

APlacementDeviceActor* UThrowLibrary::PlaceDevice(const FPlaceParametersSimple& PlaceParameters) {
    return NULL;
}

FShieldPlacement UThrowLibrary::ComputeSmoothShieldPlacement(const AActor* ShieldedActor, const float ShieldDistanceToActor, const AActor* Shield, const float DeltaSeconds, const float RotationInterpolationSpeed, const float LocationInterpolationSpeed) {
    return FShieldPlacement{};
}

FShieldPlacement UThrowLibrary::ComputeShieldPlacement(const AActor* ShieldedActor, const float ShieldDistanceToActor) {
    return FShieldPlacement{};
}


