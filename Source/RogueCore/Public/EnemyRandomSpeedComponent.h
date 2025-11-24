#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RandRange.h"
#include "EnemyRandomSpeedComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UEnemyRandomSpeedComponent : public UActorComponent {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ChanceToTrigger;

    TArray<float> Speeds;

    FRandRange CheckInterval;

    FRandRange Duration;

public:
    UEnemyRandomSpeedComponent(const FObjectInitializer& ObjectInitializer);
};
