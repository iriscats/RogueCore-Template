#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UObject/UnrealType.h"
#include "FSDSoundData.h"
#include "AudioFunctionLibrary.generated.h"

class AActor;
class UAudioComponent;
class UObject;
class USceneComponent;
class USoundAttenuation;
class USoundClass;
class USoundConcurrency;
class USoundMix;
UCLASS(Blueprintable)
class UAudioFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UAudioFunctionLibrary();
    UFUNCTION(BlueprintCallable)
    static UAudioComponent* SpawnFSDSoundAttached(const FFSDSoundData& soundData, USceneComponent* AttachToComponent, FName AttachPointName, FVector Location, FRotator Rotation, TEnumAsByte<EAttachLocation::Type> LocationType, bool bStopWhenAttachedToDestroyed, float VolumeMultiplier, float PitchMultiplier, float StartTime, USoundAttenuation* AttenuationSettings, USoundConcurrency* ConcurrencySettings, bool bAutoDestroy);
    
    static UAudioComponent* SpawnFSDSoundAtLocation(AActor* soundOwner, const FFSDSoundData& soundData, FVector Location, FRotator Rotation, float VolumeMultiplier, float PitchMultiplier, float StartTime, USoundAttenuation* AttenuationSettings, USoundConcurrency* ConcurrencySettings, bool bAutoDestroy);
    static float SetSoundClassVolume(USoundClass* SoundClass, float Volume);
    static void PushTimedSoundMix(UObject* ContextObject, USoundMix* mix, float Duration);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetSoundClassVolume(USoundClass* SoundClass);
};
