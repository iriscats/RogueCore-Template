#pragma once
#include "CoreMinimal.h"
#include "CrossbowStuckProjectileEffect.h"
#include "CrossbowStuckProjectileEffectExploding.generated.h"

class UAudioComponent;
class UHealthComponentBase;
class USoundCue;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCrossbowStuckProjectileEffectExploding : public UCrossbowStuckProjectileEffect {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* ChemicalSoundCue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAudioComponent* ChemicalAudioComponent;
    float ChemicalReactionDelay;
    UCrossbowStuckProjectileEffectExploding(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void StartTimeoutTimer(UHealthComponentBase* destroyed);
    void EnableTimeOut();
};
