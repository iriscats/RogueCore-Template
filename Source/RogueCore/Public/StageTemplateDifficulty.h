#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "StageTemplateDifficulty.generated.h"

UCLASS(Blueprintable)
class UStageTemplateDifficulty : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StageEnemyCountModifier;
    
    float StageEnemyDamageModifier;
    float StageResistanceModifier_SmallEnemies;
    float StageResistanceModifier_MediumEnemies;
    float StageResistanceModifier_LargeEnemies;
    float WaveIntervalMultiplier;
    float RoomEncounterScale;
    float StationaryEnemyScale;
    int32 EliteCommonCount;
    int32 DisruptiveEnemyCount;
    int32 SpecialEnemyCount;
    UStageTemplateDifficulty();
};
