#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SavableDataAsset.h"
#include "PlanetZone.generated.h"

class UBiome;
class UFSDSaveGame;
UCLASS(Blueprintable)
class UPlanetZone : public USavableDataAsset {
    GENERATED_BODY()
    

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText ZoneName;
    
    TArray<UBiome*> Biomes;
    bool MustBeUnlocked;
    UPlanetZone();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UBiome* PickBiome(FRandomStream& Random) const;
    bool IsUnlocked(const UFSDSaveGame* SaveGame) const;
    bool HasBiome(const UBiome* Biome) const;
    FText GetZoneName() const;
    TArray<UBiome*> GetBiomes() const;
};
