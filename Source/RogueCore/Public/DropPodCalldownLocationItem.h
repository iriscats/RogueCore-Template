#pragma once
#include "CoreMinimal.h"
#include "GenerationItem.h"
#include "Templates/SubclassOf.h"
#include "DropPodCalldownLocationItem.generated.h"

class AActor;
UCLASS(Blueprintable, NoExport)
class ADropPodCalldownLocationItem : public AGenerationItem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> CalldownClass;
    
    ADropPodCalldownLocationItem(const FObjectInitializer& ObjectInitializer);
};
