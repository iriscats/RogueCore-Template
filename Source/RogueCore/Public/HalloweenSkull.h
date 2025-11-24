#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Curves/CurveFloat.h"
#include "EnemyDeepPathfinderCharacter.h"
#include "HalloweenSkull.generated.h"

UCLASS(Blueprintable, NoExport)
class AHalloweenSkull : public AEnemyDeepPathfinderCharacter {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    FVector WobbleSpeeds;

    

    FVector WobbleRanges;

    FRuntimeFloatCurve AlertedMovement;

    float AlertedMovementScale;

    float AlertedMovementTimeScale;

    float JawMovementSpeed;

    AHalloweenSkull(const FObjectInitializer& ObjectInitializer);



public:
protected:
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
