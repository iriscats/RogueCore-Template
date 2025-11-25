#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EEnemyHealthScaling.h"
#include "DifficultyManager.generated.h"

class AFSDGameMode;
class AFSDGameState;
class UDifficultySetting;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UDifficultyManager : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinModifierEnemyCount;
    
    float MinModifierAttackCooldown;
    float MinModifierSpeed;
    int32 ForcedPlayerCount;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AFSDGameMode* GameMode;
    AFSDGameState* GameState;
    UDifficultyManager(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    UDifficultySetting* SelectDifficulty(int32 Index);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetSpeedModifier() const;
    float GetPointExtractionScaler() const;
    float GetEnemyDamageResistance(EEnemyHealthScaling healthScaling) const;
    float GetEnemyDamageModifier() const;
    float GetEnemyCountModifier() const;
    UDifficultySetting* GetCurrentDifficulty() const;
    float GetBossDifficultyScaler() const;
};
