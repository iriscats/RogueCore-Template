#pragma once
#include "CoreMinimal.h"
#include "CommunicationCharacterSettings.h"
#include "CommunicationSettings.generated.h"

UCLASS(Blueprintable, DefaultConfig, Config=Game)
class ROGUECORE_API UCommunicationSettings : public UDeveloperSettings {
    GENERATED_BODY()
    

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCommunicationCharacterSettings CharacterSettings;

    UCommunicationSettings();

};
