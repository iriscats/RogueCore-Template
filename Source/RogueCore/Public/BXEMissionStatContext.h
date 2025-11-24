#pragma once
#include "CoreMinimal.h"
#include "BXEMissionStatContext.generated.h"

class UBXEStartingWeapon;
class URunTemplate;
USTRUCT(BlueprintType)
struct FBXEMissionStatContext {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URunTemplate* Run;
    
    UBXEStartingWeapon* StartingWeapon;
    ROGUECORE_API FBXEMissionStatContext();
};
