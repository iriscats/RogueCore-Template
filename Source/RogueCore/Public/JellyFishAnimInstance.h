#pragma once
#include "CoreMinimal.h"
#include "EnemyAnimInstance.h"
#include "JellyFishAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UJellyFishAnimInstance : public UEnemyAnimInstance {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float HorizontalAngle;

    float VerticalSpeed;
    UJellyFishAnimInstance(const FObjectInitializer& ObjectInitializer);
};
