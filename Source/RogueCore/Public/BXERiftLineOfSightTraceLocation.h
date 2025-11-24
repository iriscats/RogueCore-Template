#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "BXERiftLineOfSightTraceLocation.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UBXERiftLineOfSightTraceLocation : public USceneComponent {
    GENERATED_BODY()
public:
    UBXERiftLineOfSightTraceLocation(const FObjectInitializer& ObjectInitializer);
};
