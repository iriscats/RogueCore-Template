#pragma once
#include "CoreMinimal.h"

#include "Engine/DataAsset.h"
#include "GrenadeProjectionSettings.generated.h"

UCLASS(Blueprintable)
class UGrenadeProjectionSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> SplinePoints;
    
    float ProjectionScale;
    float VelocityScale;
    bool ProjectionVisible;
    UGrenadeProjectionSettings();
};
