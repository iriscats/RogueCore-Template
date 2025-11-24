#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TerrainType.generated.h"

class UFXSystemAsset;
class USoundCue;
UCLASS(Blueprintable, MinimalAPI)
class UTerrainType : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 Collide: 1;
    
    uint8 Diggable: 1;
    uint8 Precious: 1;
    USoundCue* DebrisStandardSoundCue;
protected:
    TSoftObjectPtr<UFXSystemAsset> DebrisStandardParticles;
    UTerrainType();
};
