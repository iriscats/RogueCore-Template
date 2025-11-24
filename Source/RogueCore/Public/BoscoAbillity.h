#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EBoscoAbillityTargetPreference.h"
#include "BoscoAbillity.generated.h"

class UAbilityExitStrategy;
class UAnimSequenceBase;
class UDialogDataAsset;
UCLASS(Blueprintable)
class UBoscoAbillity : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AbillityName;
    
    UAnimSequenceBase* AbillityAnimation;
    UDialogDataAsset* VoiceOnUse;
    EBoscoAbillityTargetPreference TargetType;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAbilityExitStrategy* ExitStrategy;
    float CoolDown;
    float WindUp;
    float Duration;
    float Range;
    float RechargeTime;
    int32 MaxCharges;
    bool TargetActorIfValid;
    bool RotateTowardsTarget;
    UBoscoAbillity();
};
