#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EAbilityAmountType.h"
#include "AbilitySpawnActor.generated.h"

UCLASS(Blueprintable, NoExport)
class ROGUECORE_API AAbilitySpawnActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float amount;

    float Lifetime;
    EAbilityAmountType Type;
    AAbilitySpawnActor(const FObjectInitializer& ObjectInitializer);
};
