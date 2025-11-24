#pragma once
#include "CoreMinimal.h"
#include "AfflictionEffect.h"
#include "PlayerCharacterMontageAfflictionEffect.generated.h"

class UAnimMontage;
UCLASS(Blueprintable)
class UPlayerCharacterMontageAfflictionEffect : public UAfflictionEffect {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* FP_Montage;
    
    UAnimMontage* TP_Montage;
    float BlendOut;
    TArray<FName> RandomStarts;
    UPlayerCharacterMontageAfflictionEffect();
};
