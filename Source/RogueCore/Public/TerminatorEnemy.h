#pragma once
#include "CoreMinimal.h"
#include "EnemyDeepPathfinderCharacter.h"
#include "MultiTargeter.h"
#include "TerminatorEnemy.generated.h"

class AActor;
class UAnimMontage;
class UHitReactionComponent;
UCLASS(Blueprintable, NoExport)
class ATerminatorEnemy : public AEnemyDeepPathfinderCharacter, public IMultiTargeter {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* FlairAnimation;
    
    float MinFlairAnimCooldown;
    float MaxFlairAnimationCooldown;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHitReactionComponent* HitReactions;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSet<AActor*> CurrentTargets;
    ATerminatorEnemy(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_PlayFlairAnimation();
    // Fix for true pure virtual functions not being implemented
};
