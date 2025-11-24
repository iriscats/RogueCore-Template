#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Templates/SubclassOf.h"
#include "ProceduralSettings.generated.h"

class AProceduralSetup;
class UBiome;
class URoomDecorationObject;
UCLASS(Blueprintable)
class UProceduralSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URoomDecorationObject* MiningpodCalldownLocationDecoration;
    
    TSoftObjectPtr<UBiome> TestBiome;
    UBiome* DefaultBiome;
    TArray<FText> GenericBiomeQuotes;
    TSubclassOf<AProceduralSetup> CaveGeneratorPLSClass;
    UProceduralSettings();
};
