#include "AudioFunctionLibrary.h"

UAudioFunctionLibrary::UAudioFunctionLibrary() {
}

UAudioComponent* UAudioFunctionLibrary::SpawnFSDSoundAttached(const FFSDSoundData& soundData, USceneComponent* AttachToComponent, FName AttachPointName, FVector Location, FRotator Rotation, TEnumAsByte<EAttachLocation::Type> LocationType, bool bStopWhenAttachedToDestroyed, float VolumeMultiplier, float PitchMultiplier, float StartTime, USoundAttenuation* AttenuationSettings, USoundConcurrency* ConcurrencySettings, bool bAutoDestroy) {
    return NULL;
}

UAudioComponent* UAudioFunctionLibrary::SpawnFSDSoundAtLocation(AActor* soundOwner, const FFSDSoundData& soundData, FVector Location, FRotator Rotation, float VolumeMultiplier, float PitchMultiplier, float StartTime, USoundAttenuation* AttenuationSettings, USoundConcurrency* ConcurrencySettings, bool bAutoDestroy) {
    return NULL;
}

float UAudioFunctionLibrary::SetSoundClassVolume(USoundClass* SoundClass, float Volume) {
    return 0.0f;
}

void UAudioFunctionLibrary::PushTimedSoundMix(UObject* ContextObject, USoundMix* mix, float Duration) {
}

float UAudioFunctionLibrary::GetSoundClassVolume(USoundClass* SoundClass) {
    return 0.0f;
}


