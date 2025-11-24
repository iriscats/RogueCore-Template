#pragma once
#include "CoreMinimal.h"
#include "AttackBaseComponent.h"
#include "NameDelegateDelegate.h"
#include "SpecialAttackComponent.generated.h"

class UAnimMontage;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class USpecialAttackComponent : public UAttackBaseComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAnimMontage*> Montages;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNameDelegate OnAttackActionNotify;
    USpecialAttackComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void TriggerAttack(FName Name);
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UAnimMontage* SelectMontage() const;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Receive_OnPerformAttack();
    void Receive_OnAborted();
    void OnMontageEnded(UAnimMontage* Montage, bool interrupted);
    void OnFrozen(bool IsFrozen);
};
