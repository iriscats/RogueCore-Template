#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "Templates/SubclassOf.h"
#include "ShowroomStage.generated.h"

class USceneCaptureComponent2D;
class USceneComponent;
class UShowroomController;
class UTextureRenderTarget2D;
UCLASS(Abstract, Blueprintable, NoExport)
class AShowroomStage : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    float MinPitch;

    float MaxPitch;

    FVector2D RenderTargetResolution;

    USceneComponent* MeshRootComponent;

    USceneComponent* CameraFocusPoint;

    AShowroomStage(const FObjectInitializer& ObjectInitializer);



public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneCaptureComponent2D* SceneCapure;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneCaptureComponent2D* ActiveCaptureComponent;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<UShowroomController> ControllerClass;
    UShowroomController* ControllerInstance;
    USceneCaptureComponent2D* SceneCapture;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinPitch;
    float MaxPitch;
    FVector2D RenderTargetResolution;
    USceneComponent* MeshRootComponent;
    USceneComponent* CameraFocusPoint;
    AShowroomStage(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveInitialize(UTextureRenderTarget2D* RenderTarget);
    UFUNCTION(BlueprintCallable)
    USceneCaptureComponent2D* GetActiveCaptureComponent();
};
