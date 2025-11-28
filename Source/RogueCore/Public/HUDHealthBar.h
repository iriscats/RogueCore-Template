#pragma once
#include "CoreMinimal.h"

#include "EHealthbarType.h"
#include "FSDUserWidget.h"
#include "HUDHealthBarSignatureDelegate.h"
#include "HealthBarLooks.h"
#include "HUDHealthBar.generated.h"

class IHealth;
class UHealth;
UCLASS(Abstract, Blueprintable, EditInlineNew)
class UHUDHealthBar : public UFSDUserWidget {
    GENERATED_BODY()
    


public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHUDHealthBarSignature OnOwnerDead;
    
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor BackgroundColor;
    FLinearColor HealthColor;
    FLinearColor DamageColor;
    TMap<EHealthbarType, FHealthBarLooks> HealthBarLooks;
    FLinearColor OutlineColor;
    int32 OutlineThickness;
    float HealthAnimationFactor;
    float HealthPerCell;
    int32 MinHealthCells;
    int32 MaxHealthCells;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TScriptInterface<IHealth> TargetHealth;
    float AnimatedHealth;
    float MaxHealth;
    UHUDHealthBar();
    UFUNCTION(BlueprintCallable)
    void SetHealthComponent(const TScriptInterface<IHealth>& Health, float Damage);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCurrentHealth() const;
};
