#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AbilitySettings.generated.h"

class USoundCue;
UCLASS(Blueprintable)
class ROGUECORE_API UAbilitySettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* ErrorSound;
    
    USoundCue* BecomeAvailableSound;
    UAbilitySettings();
};
