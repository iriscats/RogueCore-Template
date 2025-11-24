#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UseAnimationSetting.generated.h"

class UAnimMontage;
UCLASS(Blueprintable)
class UUseAnimationSetting : public UDataAsset {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* BeginFP;
    
    TArray<UAnimMontage*> LoopsFP;
    UAnimMontage* EndFP;
    UAnimMontage* BeginTP;
    TArray<UAnimMontage*> LoopsTP;
    UAnimMontage* EndTP;
    UAnimMontage* CompletedFP;
    UAnimMontage* CompletedTP;
    bool IsManuallyControlled;
    bool BlockUseWhileActive;
    float BlockUseWhileActiveDuration;
    UUseAnimationSetting();
};
