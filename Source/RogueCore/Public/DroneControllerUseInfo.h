#pragma once
#include "CoreMinimal.h"

#include "DroneControllerUseInfo.generated.h"

class AActor;
USTRUCT(BlueprintType)
struct FDroneControllerUseInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector CameraLocation = FVector::ZeroVector;
    
    FRotator ViewAngle;
    TWeakObjectPtr<AActor> Target;
    FVector HitLocation;

};
