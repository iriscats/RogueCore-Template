#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GenerationItem.generated.h"

UCLASS(Abstract, Blueprintable)
class AGenerationItem : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool visible;
    
    bool AddToLevel;
    AGenerationItem(const FObjectInitializer& ObjectInitializer);
};
