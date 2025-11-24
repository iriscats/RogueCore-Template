#pragma once
#include "CoreMinimal.h"
#include "ShowroomStage.h"
#include "PlanetShowroomStage.generated.h"

class USceneComponent;
UCLASS(Abstract, Blueprintable, NoExport)
class APlanetShowroomStage : public AShowroomStage {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* CameraZoomInPoint;
    
    USceneComponent* CameraZoomOutPoint;
    APlanetShowroomStage(const FObjectInitializer& ObjectInitializer);
};
