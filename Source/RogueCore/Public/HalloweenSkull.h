#pragma once
#include "CoreMinimal.h"

#include "Curves/CurveFloat.h"
#include "EnemyDeepPathfinderCharacter.h"
#include "HalloweenSkull.generated.h"

UCLASS(Blueprintable)
class AHalloweenSkull : public AEnemyDeepPathfinderCharacter {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector WobbleSpeeds;
    
    FVector WobbleRanges;
    FRuntimeFloatCurve AlertedMovement;
    float AlertedMovementScale;
    float AlertedMovementTimeScale;
    float JawMovementSpeed;
    AHalloweenSkull(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnJawClosed();
    UFUNCTION(BlueprintCallable)
    void OnAlert();
};
