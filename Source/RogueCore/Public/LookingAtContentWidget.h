#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LookingAtContentWidget.generated.h"

class AActor;
class IHealth;
class UHealth;
class UHackingUsableComponent;
class UPawnAfflictionComponent;
class UPetComponent;
class USimpleObjectInfoComponent;
UCLASS(Abstract, Blueprintable, EditInlineNew)
class ULookingAtContentWidget : public UUserWidget {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))

    TWeakObjectPtr<UPawnAfflictionComponent> CurrentTargetAfflictions;

    TWeakObjectPtr<USimpleObjectInfoComponent> CurrentTargetInfo;

    TScriptInterface<IHealth> CurrentTargetHealth;

    TWeakObjectPtr<UHackingUsableComponent> CurrentHackingComponent;

    TWeakObjectPtr<UPetComponent> CurrentPetComponent;

    bool bWeakPointHit;

    ULookingAtContentWidget();

    UFUNCTION(BlueprintCallable)

    void UpdateCurrentTarget(float DeltaSeconds, AActor* InTargetActor, const TScriptInterface<IHealth>& InTargetHealthComponent);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> CurrentTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPawnAfflictionComponent> CurrentTargetAfflictions;
    TWeakObjectPtr<USimpleObjectInfoComponent> CurrentTargetInfo;
    TScriptInterface<IHealth> CurrentTargetHealth;
    TWeakObjectPtr<UHackingUsableComponent> CurrentHackingComponent;
    TWeakObjectPtr<UPetComponent> CurrentPetComponent;
    bool bWeakPointHit;
    ULookingAtContentWidget();
    UFUNCTION(BlueprintCallable)
    void UpdateCurrentTarget(float DeltaSeconds, AActor* InTargetActor, const TScriptInterface<IHealth>& InTargetHealthComponent);
    void RegisterWeakPointHit();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveUpdateTarget(AActor* InCurrentTarget, float DeltaTime);
    void ReceiveNewTarget(AActor* InCurrentTarget);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetTargetOwnerName() const;
    FText GetTargetName() const;
    float GetTargetHealthPct() const;
};
