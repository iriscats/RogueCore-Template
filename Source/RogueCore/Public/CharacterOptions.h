#pragma once
#include "CoreMinimal.h"
#include "CharacterOptions.generated.h"

USTRUCT(BlueprintType)
struct FCharacterOptions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool GrapplingHookAutoSwitch;
    
    bool ZiplineGunAutoSwitch;
    bool HoldToBreakImmobilization;
    bool HoldToFire;
    ROGUECORE_API FCharacterOptions();
};
