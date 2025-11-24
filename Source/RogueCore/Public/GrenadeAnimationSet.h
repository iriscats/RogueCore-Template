#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GrenadeAnimationSet.generated.h"

class UAnimMontage;
UCLASS(Blueprintable)
class UGrenadeAnimationSet : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* FP_EquipAnimation;
    
    UAnimMontage* TP_EquipAnimation;
    UAnimMontage* FP_ThrowAnimation;
    UAnimMontage* TP_ThrowAnimation;
    UGrenadeAnimationSet();
};
