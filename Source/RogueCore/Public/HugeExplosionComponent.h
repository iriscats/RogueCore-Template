#pragma once
#include "CoreMinimal.h"

#include "Components/ActorComponent.h"
#include "HugeExplosionComponent.generated.h"

class UFXSystemAsset;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UHugeExplosionComponent : public UActorComponent {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFXSystemAsset* ExplosionEffect;
    
    float ExplosionSpeed;
    float ExplosionSize;
    UHugeExplosionComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void TriggerExplosion(FVector Location);
};
