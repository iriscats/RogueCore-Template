#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DroneControllerUseInfo.generated.h"

class AActor;
USTRUCT(BlueprintType)
struct FDroneControllerUseInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector CameraLocation;
    
    FRotator ViewAngle;
    TWeakObjectPtr<AActor> Target;
    FVector HitLocation;
    ROGUECORE_API FDroneControllerUseInfo();
};
