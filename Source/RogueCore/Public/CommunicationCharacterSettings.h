#pragma once
#include "CoreMinimal.h"
#include "CommunicationCharacterSettings.generated.h"

class USoundClass;
USTRUCT(BlueprintType)
struct FCommunicationCharacterSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundClass* ShoutSoundClass_1P;
    
    USoundClass* ShoutSoundClass_3P;
    ROGUECORE_API FCommunicationCharacterSettings();
};
