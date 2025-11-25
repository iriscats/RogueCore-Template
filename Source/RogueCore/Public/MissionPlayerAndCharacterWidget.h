#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CharacterProgress.h"
#include "PlayerProgress.h"
#include "MissionPlayerAndCharacterWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UMissionPlayerAndCharacterWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UMissionPlayerAndCharacterWidget();
 
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateValues(int32 PlayerRank, int32 PlayerStars, int32 CharacterLevel, float CharacterProgress);
    
    UFUNCTION(BlueprintCallable)
    void StepCounter(float TimeScale, bool& CounterFinished);
    void PingPlayerRank();
    void PingCharacterLevel(int32 Level, int32 Stars);
    void InitCounter(FPlayerProgress PlayerProgressStart, FCharacterProgress CharacterProgressStart, FPlayerProgress PlayerProgressFinish, FCharacterProgress CharacterProgressFinish);
};
