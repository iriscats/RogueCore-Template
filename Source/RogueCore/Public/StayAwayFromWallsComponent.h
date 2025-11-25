#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "StayAwayFromWallsComponent.generated.h"

class AFSDGameState;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UStayAwayFromWallsComponent : public USceneComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AFSDGameState* GameState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxSpeed;
    float Acceleration;
    float BackAcceleration;
    float PointOffset;
    float AvoidSpeed;
    float GoBackSpeed;
    bool Active;
    UStayAwayFromWallsComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetIsActive(const bool IsActive);
};
