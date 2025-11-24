#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CharacterCameraController.generated.h"

class APlayerCharacter;
class UCameraComponent;
UCLASS(Blueprintable, MinimalAPI, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCharacterCameraController : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section
public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StartFOV;
    
    float targetFov;
    float TargetFOVSpeed;
private:
    APlayerCharacter* Character;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCameraComponent* Camera;
    UCharacterCameraController(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void ResetFOV(float FadeSpeed);
    void FOVChanged(float NewFOV);
    void FadeToFOVRelative(float NewTargetFov, float FadeSpeed);
    void FadeToFOV(float NewTargetFov, float FadeSpeed);
};
