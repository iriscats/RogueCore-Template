#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Item.h"
#include "AnimatedItem.generated.h"

class UAnimMontage;
class UItemCharacterAnimationSet;
class UPlayerAnimInstance;
class USkeletalMeshComponent;
class USkinnableComponent;
class UUpperBodyCharacterAnimationSet;
UCLASS(Abstract, Blueprintable, NoExport)
class AAnimatedItem : public AItem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkinnableComponent* Skinnable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UPlayerAnimInstance* FPAnimInstance;
    UPlayerAnimInstance* TPAnimInstance;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* FPMesh;
    USkeletalMeshComponent* TPMesh;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* FP_EquipAnimation;
    UAnimMontage* FP_IdleAnimation;
    UAnimMontage* TP_EquipAnimation;
    UAnimMontage* TP_IdleAnimation;
    float EquipDuration;
    UItemCharacterAnimationSet* CharacterAnimationSet;
    UUpperBodyCharacterAnimationSet* UpperBodyCharacterAnimationSet;
    bool UnHideOnEquip;
    bool HideOnUnequip;
    AAnimatedItem(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnReceiveEquippedFinished();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTransform GetMuzzle() const;
    USkeletalMeshComponent* GetItemMesh() const;
};
