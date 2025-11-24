#pragma once
#include "CoreMinimal.h"
#include "GenerationItem.h"
#include "Templates/SubclassOf.h"
#include "SpawnActorGenerationItem.generated.h"

class AActor;
class UBoxComponent;
UCLASS(Blueprintable, NoExport)
class ASpawnActorGenerationItem : public AGenerationItem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))

    UBoxComponent* Box;

    ASpawnActorGenerationItem(const FObjectInitializer& ObjectInitializer);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> ActorToSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* Box;
    ASpawnActorGenerationItem(const FObjectInitializer& ObjectInitializer);
};
