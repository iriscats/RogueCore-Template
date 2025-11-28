#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DeepPathFinderType.h"
#include "BaseCritterDescriptor.generated.h"

class AFSDPawn;
class UBiome;
class UDebrisPositioning;
UCLASS(Abstract, Blueprintable)
class UBaseCritterDescriptor : public UDataAsset {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AFSDPawn> CritterClass;
    
    TMap<UBiome*, TSoftClassPtr<AFSDPawn>> BiomeClassOverrides;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebrisPositioning* Positioning;
    DeepPathFinderType PathfinderType;
    UBaseCritterDescriptor();
};
