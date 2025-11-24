#pragma once
#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Animation/AnimNotifies/AnimNotify.h"
#include "AnimNotify_TerrainFootStep.generated.h"

class UFXSystemAsset;
UCLASS(Blueprintable, CollapseCategories, MinimalAPI)
class UAnimNotify_TerrainFootStep : public UAnimNotify {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFXSystemAsset* ParticleTemplate;
    
    FName BoneName;
    UAnimNotify_TerrainFootStep();
};
