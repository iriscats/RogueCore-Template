#pragma once
#include "CoreMinimal.h"

#include "EnemyAnimInstance.h"
#include "SimpleMovingEnemyAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class USimpleMovingEnemyAnimInstance : public UEnemyAnimInstance {
    GENERATED_BODY()
    

public:
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
    USimpleMovingEnemyAnimInstance(const FObjectInitializer& ObjectInitializer);
    USimpleMovingEnemyAnimInstance();
    UFUNCTION(BlueprintCallable)
    void SetMeshScale(float NewScale);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsNotMoving() const;
};
