#pragma once
#include "CoreMinimal.h"
#include "AbilityItem.h"
#include "DualAbilityItem.generated.h"

class UAnimMontage;
class USkeletalMeshComponent;
UCLASS(Blueprintable)
class ROGUECORE_API ADualAbilityItem : public AAbilityItem {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* FPSuitMesh2;

    USkeletalMeshComponent* TPSuitMesh2;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* Item_EquippedSecondaryMontage;
    FName SecondaryAttachSocket;
    ADualAbilityItem(const FObjectInitializer& ObjectInitializer);
};
