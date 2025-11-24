#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AfflictionEffect.h"
#include "AttachPointlightEffect.generated.h"

class UPointLightComponent;
UCLASS(Blueprintable)
class UAttachPointlightEffect : public UAfflictionEffect {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FColor LightColor;
    
    float Intensity;
    float Radius;
    FName Socket;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPointLightComponent* Light;
    UAttachPointlightEffect();
};
