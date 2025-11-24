#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EnemyAnimInstance.h"
#include "SimpleMovingEnemyAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class USimpleMovingEnemyAnimInstance : public UEnemyAnimInstance {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    float WalkCycleSpeed;

    float StartMovingSpeed;

    float StopMovingSpeed;

    float WalkCycleMinRate;

    float WalkCyclePlayRate;

    float MeshScale;

    bool IsMoving;

    USimpleMovingEnemyAnimInstance();

    UFUNCTION(BlueprintCallable)

    void SetMeshScale(float NewScale);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float Speed;
    
    FVector Velocity;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WalkCycleSpeed;
    float StartMovingSpeed;
    float StopMovingSpeed;
    float WalkCycleMinRate;
    float WalkCyclePlayRate;
    float MeshScale;
    bool IsMoving;
    USimpleMovingEnemyAnimInstance();
    UFUNCTION(BlueprintCallable)
    void SetMeshScale(float NewScale);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsNotMoving() const;
};
