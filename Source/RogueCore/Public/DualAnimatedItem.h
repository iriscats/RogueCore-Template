#pragma once
#include "CoreMinimal.h"
#include "Item.h"
#include "DualAnimatedItem.generated.h"

class UAnimInstance;
class UAnimMontage;
class UItemCharacterAnimationSet;
class UPlayerAnimInstance;
class USkeletalMeshComponent;
UCLASS(Abstract, Blueprintable, NoExport)
class ADualAnimatedItem : public AItem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimInstance* FPAnimInstance;
    
    UPlayerAnimInstance* TPAnimInstance;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* FPRMesh;
    USkeletalMeshComponent* FPLMesh;
    USkeletalMeshComponent* TPRMesh;
    USkeletalMeshComponent* TPLMesh;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* FP_EquipAnimation;
    UAnimMontage* TP_EquipAnimation;
    float EquipDuration;
    UItemCharacterAnimationSet* CharacterAnimationSet;
    ADualAnimatedItem(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    USkeletalMeshComponent* GetRItemMesh() const;
    USkeletalMeshComponent* GetLItemMesh() const;
};
