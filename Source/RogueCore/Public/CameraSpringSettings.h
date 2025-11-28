#pragma once
#include "CoreMinimal.h"

#include "CameraSpringSettings.generated.h"

USTRUCT(BlueprintType)
struct FCameraSpringSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool SpringEnabled;
    
    float StepThreshold;
    FVector2D SpringExtend;
    float RetractStrength;
    float RetractDownReduction;
    bool ShowDebug;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float LastSpeedZ;
    FVector LastLocation;
    FVector StartSpringLocation;
    bool bSpringInitialized;
    ROGUECORE_API FCameraSpringSettings();
};
