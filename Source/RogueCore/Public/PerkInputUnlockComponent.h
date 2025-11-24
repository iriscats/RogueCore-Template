#pragma once
#include "CoreMinimal.h"
#include "BXELogicUnlockComponent.h"
#include "PerkInputUnlockComponent.generated.h"

class APlayerController;
class UInputComponent;
class UPerkAsset;
UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPerkInputUnlockComponent : public UBXELogicUnlockComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))

    UInputComponent* PlayerInputComponent;

    UPerkInputUnlockComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)

    void UnbindPerkInputActions();



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PerkQuickUseIndex;
    
    FName PerkActionTriggerName1;
    FName PerkActionTriggerName2;
    UPerkAsset* Perk;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UInputComponent* PlayerInputComponent;
    UPerkInputUnlockComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void UnbindPerkInputActions();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPerkTriggered();
    void MarkPerkUsed();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPerkUnlocked() const;
    APlayerController* GetPlayerController() const;
    UPerkAsset* GetPerk() const;
    void BindPerkInputActions();
};
