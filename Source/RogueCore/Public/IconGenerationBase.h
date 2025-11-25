#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IconGenerationBase.generated.h"

class UMaterialInterface;
class USceneCaptureComponent2D;
UCLASS(Blueprintable)
class AIconGenerationBase : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneCaptureComponent2D* ActiveCaptureComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* DownScaleMaterial;
    AIconGenerationBase(const FObjectInitializer& ObjectInitializer);
};
