#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "HugeExplosionComponent.generated.h"

class UFXSystemAsset;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UHugeExplosionComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    UFXSystemAsset* ExplosionEffect;

    

    float ExplosionSpeed;

    float ExplosionSize;

    UHugeExplosionComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)

    void TriggerExplosion(FVector Location);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFXSystemAsset* ExplosionEffect;
    
    float ExplosionSpeed;
    float ExplosionSize;
    UHugeExplosionComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void TriggerExplosion(FVector Location);
};
