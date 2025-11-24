#pragma once
#include "CoreMinimal.h"
#include "ESpawnActorSpawnLocation.h"
#include "TagEffectBase.h"
#include "Templates/SubclassOf.h"
#include "TagSpawnActorEffect.generated.h"

class AActor;
UCLASS(Blueprintable, EditInlineNew)
class UTagSpawnActorEffect : public UTagEffectBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> ActorType;
    
    ESpawnActorSpawnLocation SpawnLocation;
    UTagSpawnActorEffect();
};
