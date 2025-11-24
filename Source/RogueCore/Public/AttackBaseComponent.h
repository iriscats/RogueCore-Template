#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "Templates/SubclassOf.h"
#include "AttackBaseComponent.generated.h"

class AActor;
class UAttackBaseComponent;
UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UAttackBaseComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AttackName;
    
    float MaxSurfaceAngle;
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval Range;
    float MinRange;
    float MaxRange;
    bool StaggerImmuneAttack;
    UAttackBaseComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    UAttackBaseComponent* ReplaceAttackComponent(UAttackBaseComponent* componentToReplace, TSubclassOf<UAttackBaseComponent> newComponentClass);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveCompleteAttack();
    void ReceiveAttackTarget(AActor* Target);
    void ReceiveAbortAttack();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMinRange() const;
    float GetMaxRange() const;
    void CompleteAttack(bool success);
    UFUNCTION(BlueprintCallable)
    void AttackTarget(AActor* Target);
    void AbortAttack();
};
