#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "ShowroomController.generated.h"

class AActor;
class AShowroomStage;
class UAudioComponent;
UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UShowroomController : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))

    AShowroomStage* Stage;



    // UPROPERTY fields moved from private section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))

    UAudioComponent* SpeedNotifierAudioComponent;

    FName SpeedNotifierParameterName;

    float SmoothedRotationSpeed;

    FRotator LastCameraRotation;

    UFUNCTION(BlueprintCallable)

    void ZoomShowroom(float Distance, bool instantZoom);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AShowroomStage* Stage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsZoomedIn;
    bool ZoomInProgress;
    FTransform SceneCaptureTargetTransform;
    float RotationDividerInDegrees;
    float RotationAveragingWindowInSeconds;
public:
    UShowroomController(const FObjectInitializer& ObjectInitializer);
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAudioComponent* SpeedNotifierAudioComponent;
    FName SpeedNotifierParameterName;
    float SmoothedRotationSpeed;
    FRotator LastCameraRotation;
    UFUNCTION(BlueprintCallable)
    void ZoomShowroom(float Distance, bool instantZoom);
    void ToggleZoom();
    void SetSpeedAudioNotifier(UAudioComponent* AudioComponent, const FName AudioParameterName);
    void SetLightChannels(AActor* Actor);
    void RotateShowroom(float Pitch, float Yaw);
    void ResetShowroomRotation();
    FRotator GetShowroomRotation();
};
