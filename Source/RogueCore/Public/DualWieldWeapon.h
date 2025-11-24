#pragma once
#include "CoreMinimal.h"
#include "HitscanWeapon.h"
#include "DualWieldWeapon.generated.h"

class UAnimMontage;
class UFXSystemAsset;
class UFirstPersonSkeletalMeshComponent;
class USkeletalMeshComponent;
UCLASS(Abstract, Blueprintable, NoExport)
class ADualWieldWeapon : public AHitscanWeapon {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFirstPersonSkeletalMeshComponent* FPMeshLeft;
    
    USkeletalMeshComponent* TPMeshLeft;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* WPN_Left_Reload;
    UAnimMontage* WPN_Left_ReloadEmpty;
    UAnimMontage* WPN_Left_TP_Reload;
    UFXSystemAsset* CasingParticlesLeft;
    FName MuzzleLeft;
    ADualWieldWeapon(const FObjectInitializer& ObjectInitializer);
};
