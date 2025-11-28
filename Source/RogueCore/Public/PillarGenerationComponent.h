#pragma once
#include "CoreMinimal.h"

#include "GenerationComponent.h"
#include "PillarGenerationComponent.generated.h"

class UPillarSettings;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UPillarGenerationComponent : public UGenerationComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> Points;
    
    bool visible;
    UPillarSettings* PillarSettings;
    UPillarGenerationComponent(const FObjectInitializer& ObjectInitializer);
};
