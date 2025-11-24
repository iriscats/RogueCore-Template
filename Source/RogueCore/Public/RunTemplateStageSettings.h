#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "RunTemplateStageSettings.generated.h"

class ADebrisDataActor;
class AProceduralSetup;
class UBiome;
class UDebrisActorComponent;
class UMissionDNA;
class UStageTemplate;
USTRUCT(BlueprintType)
struct FRunTemplateStageSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStageTemplate* ForcedTemplate;
    
    TSoftClassPtr<AProceduralSetup> ForcedPLS;
    TSubclassOf<UMissionDNA> ForcedDNA;
    UBiome* ForcedBiome;
    TSoftClassPtr<ADebrisDataActor> DebrisActor;
    TArray<TSoftClassPtr<UDebrisActorComponent>> DebrisComponents;
    ROGUECORE_API FRunTemplateStageSettings();
};
