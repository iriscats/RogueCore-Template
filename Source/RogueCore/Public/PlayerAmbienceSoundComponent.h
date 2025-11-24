#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RandRange.h"
#include "PlayerAmbienceSoundComponent.generated.h"

class APlayerCharacter;
class USoundCue;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPlayerAmbienceSoundComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))

    APlayerCharacter* Character;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    TArray<TSoftObjectPtr<USoundCue>> SoundCuesToPlay;

    FRandRange SpawnAmbienceIntervalSeconds;

    float RangeFromPlayer;

    bool IsEnabled;

    UPlayerAmbienceSoundComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)

    void PlayAmbience();



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APlayerCharacter* Character;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<USoundCue>> SoundCuesToPlay;
    FRandRange SpawnAmbienceIntervalSeconds;
    float RangeFromPlayer;
    bool IsEnabled;
    UPlayerAmbienceSoundComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void PlayAmbience();
};
