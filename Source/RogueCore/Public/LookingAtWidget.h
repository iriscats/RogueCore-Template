#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LookingAtWidget.generated.h"

class AActor;
class APlayerCharacter;
class IHealth;
class UHealth;
class UCharacterSightComponent;
class UHealthComponentBase;
class UPawnAfflictionComponent;
UCLASS(Blueprintable, EditInlineNew)
class ULookingAtWidget : public UUserWidget {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TargetSelectDuration;
    
    float TargetLostDuration;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<APlayerCharacter> Character;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UCharacterSightComponent> CharacterSight;
    TWeakObjectPtr<AActor> CurrentTarget;
    TWeakObjectPtr<UPawnAfflictionComponent> CurrentTargetAfflictions;
    TScriptInterface<IHealth> CurrentTargetHealth;
    bool CanCurrentTargetTakeDamage;
    float TargetLostTime;
    bool bTargetSet;
    ULookingAtWidget();
    UFUNCTION(BlueprintCallable)
    void SetCurrentTarget(AActor* NewActor, const TScriptInterface<IHealth>& HealthComponent, float OverrideTargetLostTime);
    void ResetCurrentTarget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveUpdateTarget(AActor* InCurrentTarget, float DeltaTime);
    void ReceiveTargetLost();
    void ReceiveNewTarget(AActor* InCurrentTarget);
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    bool IsValidTarget(AActor* targetActor, const TScriptInterface<IHealth>& TargetHealth) const;
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsBossFight(const TScriptInterface<IHealth>& Health) const;
    UHealthComponentBase* GetLookingAtHealth() const;
    AActor* GetLookingAtActor() const;
};
