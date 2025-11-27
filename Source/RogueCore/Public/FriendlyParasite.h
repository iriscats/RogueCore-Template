#pragma once
#include "CoreMinimal.h"

#include "EnemyDeepPathfinderCharacter.h"
#include "IsAttackingDelegate.h"
#include "FriendlyParasite.generated.h"

class AActor;
class AFSDPawn;
class UDamageComponent;
class UHealthComponentBase;
class UPrimitiveComponent;
class USphereComponent;
UCLASS(Blueprintable)
class AFriendlyParasite : public AEnemyDeepPathfinderCharacter {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIsAttacking OnIsAttackingEvent;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* Collision;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* FindEnemyCollision;
    UDamageComponent* DamageComponent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MoveSpeed;
    float DamageBeforeDeath;
    bool CountDirectDMG;
    bool CountAreaDMG;
    float StartFollowRange;
    float DamageRange;
    float DamageTime;

    float FoldoutRange;
    float SpinRange;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    AFSDPawn* TargetEnemy;
    AFriendlyParasite(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SelectNewTarget(UHealthComponentBase* Health);
    void OnEnemyCollisionEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
