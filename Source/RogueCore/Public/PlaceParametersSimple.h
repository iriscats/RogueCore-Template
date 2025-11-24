#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "PlaceParametersSimple.generated.h"

class APlacementDeviceActor;
class APlayerCharacter;
USTRUCT(BlueprintType)
struct FPlaceParametersSimple {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<APlacementDeviceActor> PlacementClass;
    
    APlayerCharacter* PlacingCharacter;
    float ForwardPlaceDistance;
    ROGUECORE_API FPlaceParametersSimple();
};
