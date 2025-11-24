#pragma once
#include "CoreMinimal.h"
#include "EGymDifficulty.generated.h"

UENUM()
enum class EGymDifficulty : int32 {
    Easy = 40,
    Normal = 35,
    Hard = 30,
    Rival = 25,
    Glyphid = 20,
    CoreSpawn = 15,
    Dwarf = 10,
    Reclaimer = 5,
    Karl = 3,
    Full = 100,
};
