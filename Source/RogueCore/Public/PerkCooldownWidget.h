#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PerkCooldownWidget.generated.h"

class AActor;
class UPerkAsset;
UCLASS(Abstract, Blueprintable, EditInlineNew)
class UPerkCooldownWidget : public UUserWidget {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section
public:
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* MonitoredCharacter;
    
    UPerkAsset* MonitoredPerk;
    float currentProgress;
    UPerkCooldownWidget();
 
    UFUNCTION(BlueprintCallable)
    void SetMonitoredPerk(AActor* Character, UPerkAsset* Perk);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnCooldownProgressChanged(const float Progress);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCoolDownProgress() const;
    void ClearMonitoredPerk();
};
