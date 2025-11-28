#pragma once
#include "CoreMinimal.h"
#include "CharacterStateComponent.h"
#include "EInputKeys.h"
#include "WalkingStateComponent.generated.h"

class APlayerCharacter;
class UAudioComponent;
class USoundBase;
class UTrackBuilderMovement;
UCLASS(Blueprintable, MinimalAPI, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UWalkingStateComponent : public UCharacterStateComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool SlidingEnabled;
    
    bool ShowDebug;
    float SlideAngle;
    float SlideAcceleration;
    float MaxSlideSpeed;
    float MaxClimbDistance;
    USoundBase* AudioSliding;
    USoundBase* IceSliding;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAudioComponent* AudioComponentSliding;
    UAudioComponent* AudioComponentIceSliding;
    UWalkingStateComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void TrackGrindCallback(APlayerCharacter* User, EInputKeys Key);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_StartTrackMovement(UTrackBuilderMovement* InMovement);
    UFUNCTION(Reliable, Server)
    void Server_SetIsSliding(bool isSliding);
    void JumpPress();
};
