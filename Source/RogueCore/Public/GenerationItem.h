#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GenerationItem.generated.h"

UCLASS(Abstract, Blueprintable, NoExport)
class AGenerationItem : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    bool visible;

    

    bool AddToLevel;

    AGenerationItem(const FObjectInitializer& ObjectInitializer);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool visible;
    
    bool AddToLevel;
    AGenerationItem(const FObjectInitializer& ObjectInitializer);
};
