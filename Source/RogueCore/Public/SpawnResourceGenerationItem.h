#pragma once
#include "CoreMinimal.h"
#include "GenerationItem.h"
#include "SpawnResourceGenerationItem.generated.h"

class UResourceData;
class USphereComponent;
UCLASS(Blueprintable, NoExport)
class ASpawnResourceGenerationItem : public AGenerationItem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UResourceData* Resource;
    
    float BaseAmount;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* Sphere;
    ASpawnResourceGenerationItem(const FObjectInitializer& ObjectInitializer);
};
