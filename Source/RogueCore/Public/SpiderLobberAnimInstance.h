#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ShootingSpiderAnimInstance.h"
#include "SpiderLobberAnimInstance.generated.h"

class UHealthComponentBase;
UCLASS(Blueprintable, NonTransient)
class USpiderLobberAnimInstance : public UShootingSpiderAnimInstance {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector EffectiveLiquidInBum;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval LiquidInBumRange;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LiquidInBumEaseInExp;
    float LiquidInBumTimeToMax;
    float LiquidInBumTimeToMaxShort;
    USpiderLobberAnimInstance(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetAttackIndex(int32 Index);
    void ResetLiquidInBum();
    void OnDeath(UHealthComponentBase* InHealthComponent);
};
