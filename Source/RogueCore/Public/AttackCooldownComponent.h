#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttackCooldown.h"
#include "AttackCooldownComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UAttackCooldownComponent : public UActorComponent {
    GENERATED_BODY()
    

public:
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAttackCooldown> AttackCooldowns;
    
    UAttackCooldownComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetCooldown(const FName& AttackName, float cooldownSeconds);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAttackOffCooldown(const FName& AttackName) const;
    bool IsAnyAttackOffCooldown() const;
    void AttackUsed(const FName& Name);
};
