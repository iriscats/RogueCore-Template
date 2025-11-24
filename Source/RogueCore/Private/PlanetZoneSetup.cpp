#include "PlanetZoneSetup.h"

UPlanetZoneSetup::UPlanetZoneSetup() {
}

TArray<UPlanetZone*> UPlanetZoneSetup::GetPlanetZones() const {
    return TArray<UPlanetZone*>();
}

UPlanetZone* UPlanetZoneSetup::GetPlanetZoneForBiome(const UBiome* Biome, int32& zoneIndex) const {
    return NULL;
}

UPlanetZone* UPlanetZoneSetup::FindPlanetZoneForBiome(const UBiome* Biome) const {
    return NULL;
}


