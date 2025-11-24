#pragma once
#include "CoreMinimal.h"
#include "GenerationItem.h"
#include "Templates/SubclassOf.h"
#include "SpawnTriggerItem.generated.h"

class AActor;
UCLASS(Abstract, Blueprintable, NoExport)
class ASpawnTriggerItem : public AGenerationItem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    TSubclassOf<AActor> Trigger;

    

    FName Message;

    ASpawnTriggerItem(const FObjectInitializer& ObjectInitializer);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> Trigger;
    
    FName Message;
    ASpawnTriggerItem(const FObjectInitializer& ObjectInitializer);
};
