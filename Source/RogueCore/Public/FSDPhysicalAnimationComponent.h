#pragma once
#include "CoreMinimal.h"

#include "PhysicsEngine/PhysicalAnimationComponent.h"
#include "FSDPhysicalAnimationComponent.generated.h"

UCLASS(Blueprintable, MinimalAPI, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UFSDPhysicalAnimationComponent : public UPhysicalAnimationComponent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HitReactionStrength;
    
    float TimeOfHitReaction;
    UFSDPhysicalAnimationComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void RequestPhysicalHitReaction(const FVector& InForce, const FName InBoneName);
};
