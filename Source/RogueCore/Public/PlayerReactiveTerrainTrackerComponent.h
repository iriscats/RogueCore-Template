#pragma once
#include "CoreMinimal.h"
#include "ReactiveTerrainTrackerComponent.h"
#include "PlayerReactiveTerrainTrackerComponent.generated.h"

class UFSDPhysicalMaterial;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPlayerReactiveTerrainTrackerComponent : public UReactiveTerrainTrackerComponent {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UFSDPhysicalMaterial* CurrentPhysicalMaterial;
    
    UPlayerReactiveTerrainTrackerComponent(const FObjectInitializer& ObjectInitializer);
};
