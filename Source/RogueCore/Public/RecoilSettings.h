#pragma once
#include "CoreMinimal.h"
#include "RandRange.h"
#include "RecoilSettings.generated.h"

USTRUCT(BlueprintType)
struct FRecoilSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRandRange RecoilRoll;
    
    FRandRange RecoilPitch;
    FRandRange RecoilYaw;
    bool CanRecoilDown;
    float SpringStiffness;
    float CriticalDampening;
    float Mass;
    ROGUECORE_API FRecoilSettings();
};
