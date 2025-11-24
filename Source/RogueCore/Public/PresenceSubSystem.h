#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "PresenceSubSystem.generated.h"

class UDiscordWrapper;
UCLASS(Blueprintable)
class UPresenceSubSystem : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDiscordWrapper* DiscordWI;
    
    UPresenceSubSystem();
};
