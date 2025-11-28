#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/UnrealType.h"
#include "Components/SceneComponent.h"
#include "RotatingSceneComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class URotatingSceneComponent : public USceneComponent {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator DeltaRotaion;
    
    float BobbingSpeed;
    float BobbingSize;
    bool Sweep;
    bool ForceParentUp;
    ETeleportType TeleportMode;
    URotatingSceneComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void Stop();
    void Start();
};
