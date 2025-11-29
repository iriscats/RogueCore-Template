#pragma once
#include "CoreMinimal.h"
#include "CoolDownProgressStyle.h"
#include "EPerkHUDActivationLocation.h"
#include "EPerkUsageType.h"
#include "PerkEffectItem.h"
#include "SavableDataAsset.h"
#include "Templates/SubclassOf.h"
#include "PerkAsset.generated.h"

class APlayerController;
class UDialogDataAsset;
class UObject;
class UPerkActivationWidget;
class UPerkHUDIconWidget;
class UPerkLogic;
class UPlayerCharacterID;
class UTexture2D;
UCLASS(Blueprintable)
class ROGUECORE_API UPerkAsset : public USavableDataAsset {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Title;
    
    UTexture2D* Icon;
    int32 PlayerRequiredLevel;
    int32 EnhancementPointCost;
    TArray<TSoftClassPtr<UPerkLogic>> LogicClasses;
    TArray<FPerkEffectItem> effects;
    int32 MaxUseCharges;
    UDialogDataAsset* ShoutOnUseCharge;
    float CoolDownBetweenUse;
    FCoolDownProgressStyle CooldownUI;
    TSoftClassPtr<UPerkHUDIconWidget> HudIconWidgetClass;
    TArray<TSoftClassPtr<UPerkActivationWidget>> HudActivationWidgets;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsHighlighted;
    UPerkAsset();
    UFUNCTION(BlueprintCallable)
    bool UseCharge(APlayerController* PlayerController);
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    bool Unequip(UObject* WorldContext, UPlayerCharacterID* characterID);
    void SetHighlighted(UObject* WorldContext, bool IsHighlighted);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsUsageType(const EPerkUsageType InType) const;
    EPerkUsageType GetUsageType() const;
    UDialogDataAsset* GetShoutOnUse() const;
    int32 GetPlayerRequiredLevel() const;
    int32 GetMaxUses() const;
    TSubclassOf<UPerkHUDIconWidget> GetHudIconWidgetClass() const;
    TArray<TSubclassOf<UPerkActivationWidget>> GetHudActivationWidgets(EPerkHUDActivationLocation Location) const;
    FText GetDescription() const;
    int32 GetCost() const;
    FCoolDownProgressStyle GetCooldownUI() const;
    float GetCooldown() const;
    bool Equip(UObject* WorldContext, UPlayerCharacterID* characterID);
    bool CanUseCharge(APlayerController* PlayerController) const;
};
