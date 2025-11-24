#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "EliteEnemyEntry.h"
#include "EncounterRareCritterItem.h"
#include "EncounterSpecialItem.h"
#include "IRandRange.h"
#include "RandInterval.h"
#include "RandRange.h"
#include "EncounterSettings.generated.h"

class UCritterDescriptor;
class UEnemyDescriptor;
UCLASS(Blueprintable)
class UEncounterSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIRandRange StationaryEnemyCount;
    
    TArray<UEnemyDescriptor*> RCCommonEnemies;
    TArray<UEnemyDescriptor*> RCEliteCommonEnemies;
    TArray<UEnemyDescriptor*> RCSpecialEnemies;
    TArray<UEnemyDescriptor*> RCDisruptiveEnemies;
    TArray<UEnemyDescriptor*> CommonEnemies;
    TArray<UEnemyDescriptor*> SpecialEnemies;
    TArray<UEnemyDescriptor*> DisruptiveEnemies;
    TArray<UEnemyDescriptor*> StationaryEnemies;
    TArray<UCritterDescriptor*> CommonCritters;
    TArray<FEncounterRareCritterItem> RareCritters;
    TArray<FEncounterSpecialItem> SpecialEncounters;
    float RequiredDifficultyPerDiversity;
    float GlobalDifficultyScale;
    FRandInterval EncounterDifficulty;
    FRandInterval StationaryDifficulty;
    FRandRange CritterSpawnDifficulty;
    FGameplayTag SmallRoomTag;
    FGameplayTag MediumRoomTag;
    FGameplayTag LargeRoomTag;
    float SmallRoomDifficultyModifier;
    float MediumRoomDifficultyModifier;
    float LargeRoomDifficultyModifier;
    TMap<UEnemyDescriptor*, FEliteEnemyEntry> HeroEnemies;
    FRandInterval HeroEnemySpawn;
    UEncounterSettings();
};
