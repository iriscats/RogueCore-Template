#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PlanetZoneSetup.generated.h"

class UBiome;
class UPlanetZone;
UCLASS(Blueprintable)
class UPlanetZoneSetup : public UDataAsset {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UPlanetZone*> PlanetZones;
    
    UPlanetZoneSetup();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UPlanetZone*> GetPlanetZones() const;
    UPlanetZone* GetPlanetZoneForBiome(const UBiome* Biome, int32& zoneIndex) const;
    UPlanetZone* FindPlanetZoneForBiome(const UBiome* Biome) const;
};
