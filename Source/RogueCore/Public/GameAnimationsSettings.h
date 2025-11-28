#pragma once
#include "CoreMinimal.h"

#include "GameAnimationsSettings.generated.h"

UCLASS(Blueprintable, DefaultConfig, Config=Game)
class UGameAnimationsSettings : public UDeveloperSettings {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSoftObjectPath FootstepTestingSound;
    
    FSoftObjectPath FootstepTestingParticles;
    UGameAnimationsSettings();
};
