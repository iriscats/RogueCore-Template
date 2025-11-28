#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/NetSerialization.h"
#include "DualAbilityItem.h"
#include "Templates/SubclassOf.h"
#include "GuardianAbilityItem.generated.h"

class AActor;
class AAuraBubble;
class UAnimMontage;
class UDialogDataAsset;
class UPerkAsset;
UCLASS(Blueprintable)
class ROGUECORE_API AGuardianAbilityItem : public ADualAbilityItem {
    GENERATED_BODY()
    

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGuardianAbilityItemDelegate);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPerkAsset* RequiredPerkToRepelEnemies;
    UDialogDataAsset* QuickUseShout;
    UDialogDataAsset* AuraShout;
    TSubclassOf<AActor> SalvoActorClass;
    TSubclassOf<AActor> AuraClass;
    TWeakObjectPtr<AActor> SalvoInstance;
    TWeakObjectPtr<AAuraBubble> AuraInstance;
    UAnimMontage* Item_QuickUseAnim;
    UAnimMontage* Item_SecondaryQuickUseAnim;
    UAnimMontage* Item_AuraUseAnim;
    UAnimMontage* Item_SecondaryAuraUseAnim;
    UAnimMontage* FP_QuickUseAnim;
    UAnimMontage* TP_QuickUseAnim;
    UAnimMontage* FP_AuraUseAnim;
    UAnimMontage* TP_AuraUseAnim;
    float AruaDurationPerCharge;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuardianAbilityItemDelegate OnAuraActiveChanged;
    AGuardianAbilityItem(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, Server, Unreliable)
    void Server_ToggleAura(bool Active, FVector_NetQuantize Origin, FRotator Rotation);
    UFUNCTION(Server, Unreliable)
    void Server_QuickUse(FVector_NetQuantize Origin, FRotator Rotation);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAuraAvailable() const;
    bool IsAuraActive() const;
    UFUNCTION(BlueprintCallable)
    void DrainTick();
    bool CanActivateAura() const;
    void AnimationPlayed();
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_ToggleAura(bool Active, FVector_NetQuantize Origin, FRotator Rotation);
    UFUNCTION(NetMulticast, Unreliable)
    void All_QuickUse(FVector_NetQuantize Origin, FRotator Rotation);
};
