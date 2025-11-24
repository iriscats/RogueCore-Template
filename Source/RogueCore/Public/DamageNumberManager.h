#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "BuildableInfo.h"
#include "DamageNumberManager.generated.h"

class UDamageClass;
class UWidgetAnimation;
UCLASS(Blueprintable)
class UDamageNumberManager : public UTickableWorldSubsystem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section


public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UWidgetAnimation*> DirectionAnims;
    
    UWidgetAnimation* MoveUpAnimation;
    UWidgetAnimation* ShakeAnimation;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UDamageClass*> BannedDamageTypes;
    TArray<FBuildableInfo> Arr_DynamicDamageNumbers;
    UDamageNumberManager();
    UFUNCTION(BlueprintCallable)
    void TryInit();
    void OnDamageNumberExpired();
};
