#pragma once
#include "CoreMinimal.h"
#include "EnemyAnimInstance.h"
#include "StationaryEnemyAnimInstance.generated.h"

class AActor;
UCLASS(Blueprintable, NonTransient)
class UStationaryEnemyAnimInstance : public UEnemyAnimInstance {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* Target;
    
    float Yaw;
    float MappedYaw;
    float Pitch;
    float YawSpeed;
    float PitchSpeed;
    bool LookingLeft;
    bool LookingRight;
    bool IsVisible;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool InvertPitch;
    UStationaryEnemyAnimInstance();
    UFUNCTION(BlueprintCallable)
    void SetIsVisible(bool InIsVisible);
};
