#pragma once
#include "CoreMinimal.h"
#include "GenerationItem.h"
#include "SpawnResourceGenerationItem.generated.h"

class UResourceData;
class USphereComponent;
UCLASS(Blueprintable)
class ASpawnResourceGenerationItem : public AGenerationItem {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UResourceData* Resource;
    
    float BaseAmount;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* Sphere;
    ASpawnResourceGenerationItem(const FObjectInitializer& ObjectInitializer);
};
