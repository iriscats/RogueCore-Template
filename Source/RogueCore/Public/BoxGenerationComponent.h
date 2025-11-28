#pragma once
#include "CoreMinimal.h"

#include "GenerationComponent.h"
#include "BoxGenerationComponent.generated.h"

class UFloodFillSettings;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UBoxGenerationComponent : public UGenerationComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Extends;
    
    bool IsCarver;
    float NoiseRange;
    bool visible;
    UFloodFillSettings* Noise;
    UBoxGenerationComponent(const FObjectInitializer& ObjectInitializer);
};
